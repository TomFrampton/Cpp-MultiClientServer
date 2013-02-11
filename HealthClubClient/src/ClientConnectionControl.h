/*
 * @file 	 ClientConnectionControl.h
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This class is responsible for establishing and managing the connection to the server.
 */

#ifndef CLIENTCONNECTIONCONTROL_H_
#define CLIENTCONNECTIONCONTROL_H_

#include <WinSock2.h> // For sockets
#include <Windows.h>

#define IP_ADDRESS "127.0.0.1" // The IP address that the server resides on
#define CONN_PORT 8000 // The port that is used to connect to the server

namespace Tom_F
{
	class ClientConnectionControl
	{
	public:
		ClientConnectionControl();
		virtual ~ClientConnectionControl();

		void connectToHeadOffice();
		void disconnect();

		void sendMessage(char* message);

	private:
		int initWinSock();
		SOCKADDR_IN initAddressData();

		SOCKET listeningSocket;
		SOCKET connectionSocket;
	};

} /* namespace Tom_F */

#endif /* CLIENTCONNECTIONCONTROL_H_ */
