/*
 * ConnectionHandler.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include <iostream>
#include "ConnectionHandler.h"
#include "ServerMessenger.h"
#include "ServerConnectionControl.h"
#include "Guest.h"

using namespace std;

namespace Tom_F
{

	ConnectionHandler::ConnectionHandler() :
	admin(NULL),
	connection(NULL),
	maxBufferSize(0)
	{
	}

	ConnectionHandler::ConnectionHandler(const HeadOfficeAdmin* admin, SOCKET* connection, int maxBufSize) :
	admin(admin),
	connection(connection),
	maxBufferSize(maxBufSize)
	{
	}

	ConnectionHandler::~ConnectionHandler()
	{
	}
	/**
	 * Implements the pure virtual method in the Thread class. When with method is called
	 * a new thread is started which listens for input on the socket that this object
	 * is responsible for. When something is received a ServerMessenger object is
	 * called to handle the message
	 */
	void ConnectionHandler::threadStart()
	{
		// Connection ready to receive input from client. Inform client.
		sendMessage("You have been connected to the head office server");
		// This object will process any input received
		ServerMessenger messenger(this, admin);

		char recvMsg[maxBufferSize]; // The buffer for received messages
		bool connected = true; // We are connected
		while(connected)
		{
			// Listen for a message and test to make sure connection still exists
			int bytesRecv = recv(*connection, recvMsg, maxBufferSize, 0);
			if(bytesRecv <= 0)
			{
				// Connection is lost so clean up
				closesocket(*connection);
				*connection = 0;
				connected = false;
			}
			else // Message was successfully received
			{
				// Call messenger to handle the input
				messenger.processInput(string(recvMsg));
			}
		}
	}

	/**
	 * A wrapper method to send data to the client
	 * @param   message   The message to be sent
	 */
	void ConnectionHandler::sendMessage(string message) const
	{
		const char* cMessage = message.c_str(); // Convert message to char*
		send(*connection, cMessage, strlen(cMessage) + 1, 0); // Send to client
	}

	/**
	 * A wrapper method for receiving data from the client
	 * @return   string   The message that was received
	 */
	string ConnectionHandler::listenForMessage() const
	{
		char recvMsg[maxBufferSize]; // The buffer for received message
		recv(*connection, recvMsg, maxBufferSize, 0); // Listen for a message
		return string(recvMsg); // Convert to string and return
	}

} /* namespace Tom_F */
