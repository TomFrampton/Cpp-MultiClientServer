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

	void ConnectionHandler::threadStart()
	{
		sendMessage("You have been connected to the head office server");
		ServerMessenger messenger(this, admin);

		char recvMsg[maxBufferSize];
		bool connected = true;
		while(connected)
		{
			int bytesRecv = recv(*connection, recvMsg, maxBufferSize, 0);
			if(bytesRecv <= 0)
			{
				cout << "Connection lost with client " << endl;
				closesocket(*connection);
				connected = false;
			}
			else
			{
				messenger.processInput(string(recvMsg));
			}
		}
	}

	void ConnectionHandler::sendMessage(string message) const
	{
		const char* cMessage = message.c_str();
		send(*connection, cMessage, strlen(cMessage) + 1, 0);
	}

	string ConnectionHandler::listenForMessage() const
	{
		char recvMsg[maxBufferSize];
		recv(*connection, recvMsg, maxBufferSize, 0);
		return string(recvMsg);
	}

} /* namespace Tom_F */
