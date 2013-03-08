/*
 * @file 	 ServerConnectionControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */
#include <iostream>
#include <iomanip>

#include "ConnectionException.h"

#include "ServerConnectionControl.h"

using std::setw;

namespace Tom_F
{
	ServerConnectionControl::ServerConnectionControl() :
	addressData(SOCKADDR_IN()),
	listeningSocket(SOCKET()),
	connectionSocket(SOCKET()),
	admin(NULL),
	maxConnection(0),
	connections(NULL),
	findConnectionLock(PTHREAD_MUTEX_INITIALIZER)
	{
	}

	ServerConnectionControl::ServerConnectionControl(const HeadOfficeAdmin* admin) :
	// Most of these will be set properly when run is called
	addressData(SOCKADDR_IN()),
	listeningSocket(SOCKET()),
	connectionSocket(SOCKET()),
	admin(admin),
	maxConnection(0),
	connections(NULL),
	findConnectionLock(PTHREAD_MUTEX_INITIALIZER)
	{
	}

	/**
	 * Destructor. Deallocates the memory for the connections array and join()s all
	 * the connection threads
	 */
	ServerConnectionControl::~ServerConnectionControl()
	{
		free(connections); // Deallocate the connections array
		// An iterator to go through all the connection handler thread objects
		vector<shared_ptr<ConnectionHandler> >::iterator it = handlers.begin();

		// For each connection thread
		while(it != handlers.end())
		{
			shared_ptr<ConnectionHandler> threadPtr = *it; // Get the thread
			threadPtr->waitForThread(); // Wait for it to finish
			it++; // Increment iterator
		}
	}

	/**
	 * Sets up the server by binding and listening to a socket.
	 * @param   maxConnections   The maximum number of connections at once
	 */
	void ServerConnectionControl::run(int maxConnections)
	{
		this->maxConnection = maxConnections; // Set the server's max connection count
		// Allocate and zero the memory for the sockets
		connections = (SOCKET*)calloc(maxConnections, sizeof(SOCKET));

		// Start WinSock and test for error
		if(initWinSock() != 0)
		{
			throw Exception::ConnectionException("Winsock startup failed");
		}

		initAddressData(); // Initialize the address data

		// Properly create the listening and connection sockets
		listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		connectionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		// Bind listening socket and test for error
		if(bind(listeningSocket, (SOCKADDR*)&addressData, sizeof(addressData)) == SOCKET_ERROR)
		{
			throw Exception::ConnectionException("Socket bind error");
		}

		// Listen for connections and test for error
		// SOMAXCONN = keep listening for an infinite number of connections
		if(listen(listeningSocket, SOMAXCONN) == SOCKET_ERROR)
		{
			throw Exception::ConnectionException("Socket listening error");
		}

		listenForConnections(); // Everything ready, listen for connections
	}

	/**
	 * Infinitely loops to accept any incoming connections then
	 * calls processNewConnection() when one is found.
	 */
	void ServerConnectionControl::listenForConnections()
	{
		int addressLength = sizeof(addressData);

		// Listen in an infinite loop
		for(;;Sleep(10))
		{
			// Accept incoming connection and test for error
			connectionSocket = accept(listeningSocket, (SOCKADDR*)&addressData, &addressLength);
			if(connectionSocket < 0)
			{
				throw Exception::ConnectionException("Failed to connect");
			}
			else
			{
				processNewConnection(); // Everything OK, process this new connection
			}
		}
	}

	/**
	 * Starts up the winsock dll
	 * @return Returns zero if startup was successful
	 */
	int ServerConnectionControl::initWinSock()
	{
		// Set up the data needed for WinSock dll
		WSAData wsa;
		WORD wVersion = MAKEWORD(2,1);
		return WSAStartup(wVersion, &wsa); // Start Winsock dll and return result
	}

	/**
	 * Initializes  the address data struct to listen on the pre-defined port
	 * number and accept connections from any IP
	 */
	void ServerConnectionControl::initAddressData()
	{
		// Set values for the address data struct
		addressData.sin_addr.s_addr = htonl(INADDR_ANY); // Accept connections from any IP
		addressData.sin_family = AF_INET; // Using internet protocol
		addressData.sin_port = htons(CONN_PORT); // Listen on pre-defined port
	}

	/**
	 * When a new connection is established this method is used to assign it a
	 * socket from the array and start up the thread that will listen on the socket.
	 */
	void ServerConnectionControl::processNewConnection()
	{
		// Find a socket for this new connection to use
		SOCKET* newConnection = findAvailableSocket();

		// If socket was found
		if(newConnection != NULL)
		{
			*newConnection = connectionSocket; // Copy the connected socket into the array
			// Create a new connection handler for this connection as a shared_ptr
			shared_ptr<ConnectionHandler> handler(new ConnectionHandler(admin, newConnection, BUF_SIZE));
			handlers.push_back(handler); // Add to array so we can join() later
			handler->runThread(); // Run the connection handler thread
		}
		else
		{
			throw Exception::ConnectionException("Maximum number of connections reached");
		}
	}

	/**
	 * Finds the next available socket in the connections array. Uses double check locking
	 * to make sure only one thread is assigning to a socket at a time.
	 * @return A pointer to the socket that was found, or null if none were available.
	 */
	SOCKET* ServerConnectionControl::findAvailableSocket()
	{
		SOCKET* foundConnection = NULL; // No slot found yet
		// For the entire socket array
		int connectionIndex = 0;
		while(connectionIndex < maxConnection && !foundConnection)
		{
			// If an empty slot
			if(connections[connectionIndex] == 0)
			{
				// Lock the mutex so other threads can't assign to this slot at once
				pthread_mutex_lock(&findConnectionLock);

				// Recheck that this slot is still empty
				if(connections[connectionIndex] == 0)
				{
					connections[connectionIndex] = 1; // Placeholder for that socket so other threads don't take it
					foundConnection = &connections[connectionIndex]; // Save the pointer to the slot
				}

				// Unlock the mutex
				pthread_mutex_unlock(&findConnectionLock);
			}
			connectionIndex++;
		}
		// Return the slot in the array that was found
		return foundConnection;
	}

	/**
	 * This function is a friend of the ServerConnectionControl class. Overloads
	 * << operator to print information about the connection status of each socket.
	 * @param    os         Ref to the output stream to push text into
	 * @param    sc         Ref to the serverConnection object to print the details of
	 * @return   ostream&   A reference to the output stream used to allow chaining
	 */
	ostream& operator<<(ostream& os, const ServerConnectionControl& sc)
	{
		// For each socket in the connections array
		for(int i = 0; i < 10; i++)
		{
			os << "Socket " << setw(2) << i << ": "; // Print socket number
			// Test if there is a connection on this socket
			if(sc.connections[i] == 0)
			{
				os << "No connection"; // No connection
			}
			else
			{
				os << "Connection"; // Connection
			}
			os << "\n"; // Newline
		}
		return os; // Return the ouput stream to allow chaining
	}

} /* namespace Tom_F */
