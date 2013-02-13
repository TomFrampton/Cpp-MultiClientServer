/*
 * @file 	 ServerConnectionControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */
#include <iostream>
#include <iomanip>
using namespace std;

#include "ServerConnectionControl.h"
#include "NewConnectionThread.h" // The function to start a new thread for a new connection

namespace Tom_F
{
	ServerConnectionControl::ServerConnectionControl()
	{
		// Allocate and zero the memory for the sockets
		connections = (SOCKET*)calloc(MAX_CONN, sizeof(SOCKET));
		connCount = 0;
		pthread_mutex_init(&findConnectionLock, NULL);
	}

	ServerConnectionControl::~ServerConnectionControl()
	{
		free(connections); // Deallocate the socket array
	}

	/**
	 * Sets up the server by binding and listening to a socket.
	 */
	void ServerConnectionControl::run()
	{
		// Start WinSock
		if(initWinSock() != 0)
		{
			// Throw winsock exception
		}

		initAddressData();

		// Bind listening socket and test for error
		if(bind(listeningSocket, (SOCKADDR*)&addressData, sizeof(addressData)) == SOCKET_ERROR)
		{
			// Bind exception
		}

		// Listen for connections and test for error
		if(listen(listeningSocket, SOMAXCONN) == SOCKET_ERROR)
		{
			// Listen exception
		}

		listenForConnections();
	}

	/**
	 * Infinitely loops to listen for any incoming connections.
	 */
	void ServerConnectionControl::listenForConnections()
	{
		int addressLength = sizeof(addressData);
		// Listening notice
		// Listen in an infinite loop
		for(;;Sleep(10))
		{
			connectionSocket = accept(listeningSocket, (SOCKADDR*)&addressData, &addressLength);
			if(connectionSocket < 0)
			{
				// throw connecting error
			}
			else
			{
				processNewConnection();
			}
		}
	}

	/**
	 * Starts up the winsock dll
	 * @return Returns zero if startup was successful
	 */
	int ServerConnectionControl::initWinSock()
	{
		WSAData wsa;
		WORD wVersion = MAKEWORD(2,1);
		return WSAStartup(wVersion, &wsa);
	}

	/**
	 * Initializes  the address data struct and the listening/connection sockets.
	 */
	void ServerConnectionControl::initAddressData()
	{
		// Set up the listening/connection sockets
		listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		connectionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		// Set values for the address data struct
		addressData.sin_addr.s_addr = htonl(INADDR_ANY);
		addressData.sin_family = AF_INET;
		addressData.sin_port = htons(CONN_PORT);
	}

	/**
	 * When a new connection is established this method is used to assign it a socket from the array
	 * and start up the thread that will listen on the socket.
	 */
	void ServerConnectionControl::processNewConnection()
	{
		// Find a socket for this new connection to use
		SOCKET* newConnection = findAvailableSocket();

		if(newConnection != NULL)
		{
			// Assign the newly made connection to the socket that was found
			*newConnection = connectionSocket;
			// Put on heap so it doesn't go out of scope, deleted in closeConnection()
			ConnectionData* connData = new ConnectionData(this, newConnection, BUF_SIZE);


			pthread_t connectionHandler;
			pthread_create(&connectionHandler, NULL, newConnectionThread, connData);
		}
		else
		{
			// throw max connections exception
		}

	}

	/**
	 * Finds the next available socket in the connections array.
	 * @return A pointer to the socket that was found, or null if none were available.
	 */
	SOCKET* ServerConnectionControl::findAvailableSocket()
	{
		pthread_mutex_lock(&findConnectionLock);

		// For the entire socket array
		for(int i = 0; i < MAX_CONN; i++)
		{
			if(connections[i] == 0)
			{
				connections[i] = 1; // Placeholder for that socket so other threads don't take it
				pthread_mutex_unlock(&findConnectionLock);
				return &connections[i];
			}
		}

		// No slots available.
		pthread_mutex_unlock(&findConnectionLock);
		return NULL;
	}

	/**
	 * Handles the closing of a connection by closing the socket that was used by that connection.
	 * @param ConnectionData* Pointer to the connection data that the closing connection was using
	 */
	void ServerConnectionControl::closeConnection(ConnectionData* connData) const
	{
		closesocket(*connData->getSocketPtr());
		*connData->getSocketPtr() = 0;
		delete connData;
	}

	ostream& operator<<(ostream& os, const ServerConnectionControl& sc){
		for(int i = 0; i < 10; i++){
			cout << "Socket " << setw(2) << i << ": ";
			if(sc.connections[i] == 0){
				cout << "No connection";
			}
			else{
				cout << "Connection";
			}
			cout << "\n";
		}
		return os;
	}

} /* namespace Tom_F */
