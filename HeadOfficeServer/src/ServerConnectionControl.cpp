/*
 * @file 	 ServerConnectionControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include "ServerConnectionControl.h"

namespace Tom_F
{
	ServerConnectionControl::ServerConnectionControl()
	{

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
	}

	/**
	 * Infinitely loops to listen for any incoming connections.
	 */
	void ServerConnectionControl::listenForConnections()
	{
		int addressLength = sizeof(addressData);
		// Listening notice
		// Listen in an infinite loop
		for(;;Sleep(10)){
			connectionSocket = accept(listeningSocket, (SOCKADDR*)&addressData, &addressLength);
			if(connectionSocket < 0){
				// throw connecting error
			}
			else
			{
				processNewConnection();
			}
		}
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
		SOCKET& newConnection = findAvailableSocket();

		if(newConnection != 0)
		{

		}
		else
		{
			// throw max connections exception
		}

	}

	/**
	 * Finds the next available socket in the connections array.
	 * @return A reference to the socket that was found, or null if none were available.
	 */
	SOCKET& ServerConnectionControl::findAvailableSocket()
	{
		// For the entire socket array
		for(int i = 0; i < MAX_CONN; i++)
		{
			if(connections[i] == 0)
			{
				// Return first free slot
				return &connections[i];
			}
		}

		// No slots available.
		return NULL;
	}

} /* namespace Tom_F */
