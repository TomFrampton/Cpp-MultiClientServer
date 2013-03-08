/*
 * @file 	 ClientConnectionControl.h
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This class is responsible for establishing and managing the connection of a local health club to the server.
 */

#include "ConnectionException.h"
#include "ClientConnectionControl.h"

namespace Tom_F
{

	/**
	 * Constructs the object to use a default socket.
	 */
	ClientConnectionControl::ClientConnectionControl() :
	connectionSocket(SOCKET())
	{
	}

	/**
	 * Destructor. Cleans up WSA.
	 */
	ClientConnectionControl::~ClientConnectionControl()
	{
		WSACleanup();
	}

	/**
	 * Connects to the head office server if possible. Throws a connection exception if connection was unsuccesful.
	 * @throws   ConnectionException   The connection could not be established
	 */
	void ClientConnectionControl::connectToHeadOffice()
	{
		// Try to start the winsock dll
		if(initWinSock() != 0){
			throw Exception::ConnectionException("Winsock failed to initialize"); // Failed - throw exception
		}

		SOCKADDR_IN addressData = initAddressData(); // Initialize the address data
		int addressLength = sizeof(addressData); // Get the length of the address data

		connectionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Create the connection socket

		// Try to connect to the server using the address data provided
		if(connect(connectionSocket, (SOCKADDR*)&addressData, addressLength) != 0)
		{
			throw Exception::ConnectionException("Could not connect to server"); // Failed - throw exception
		}
		else
		{
			listenForMessage(); // Connection established. Listen for a confirmation message from the server.
		}
	}

	/**
	 * Disconnects from the head office and closes the connection socket.
	 */
	void ClientConnectionControl::disconnect()
	{
		closesocket(connectionSocket); // Close the connection socket.
	}

	/**
	 * Send a message accross the network.
	 * @param   message   The message to be sent
	 */
	void ClientConnectionControl::sendMessage(string message) const
	{
		const char* cMessage = message.c_str(); // Convert the string message to a char*
		send(connectionSocket, cMessage, strlen(cMessage) + 1, 0); // Send it accross the network
	}

	/**
	 * Wait to receive a message from the server.
	 * @return   string   The message that was received
	 */
	string ClientConnectionControl::listenForMessage() const
	{
		char recvMsg[BUF_SIZE]; // Create a char* for the received message
		recv(connectionSocket, recvMsg, BUF_SIZE, 0); // Wait to receive a message
		return string(recvMsg); // Convert to string and return message
	}

	/**
	 * Start up the winsock dll.
	 * @return   int   The result of the startup.
	 */
	int ClientConnectionControl::initWinSock()
	{
		WSAData wsa;
		WORD dllVersion = MAKEWORD(2,1);
		return (WSAStartup(dllVersion, &wsa)); // Start up the winsock dll and return the result
	}

	/**
	 * Initialize the address data that is going to be used to connect to the server.
	 * @return   SOCKADDR_IN   The address data that was initialized
	 */
	SOCKADDR_IN ClientConnectionControl::initAddressData()
	{
		SOCKADDR_IN addressData;

		// Set values for the address data struct
		addressData.sin_addr.s_addr = inet_addr(IP_ADDRESS);
		addressData.sin_family = AF_INET;
		addressData.sin_port = htons(CONN_PORT);

		return addressData;
	}

}
