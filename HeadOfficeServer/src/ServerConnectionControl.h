/*
 * @file 	 ServerConnectionControl.h
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This class is responsible for establishing and managing the connection with the server.
 */

#ifndef SERVERCONNECTIONCONTROL_H_
#define SERVERCONNECTIONCONTROL_H_

#include <WinSock2.h> // For sockets
#include <Windows.h>
#include <pthread.h> // For POSIX threads
#include <iostream>
#include "ConnectionData.h"

using std::ostream; // To overload the << operator

#define CONN_PORT 8000 // Server will connect on port 8000
#define BUF_SIZE 4096 // The server will accept packet sized char*
#define MAX_CONN 64 // A maximum of 64 connections at once

namespace Tom_F
{
	class ServerConnectionControl
	{
	public:
		ServerConnectionControl();
		virtual ~ServerConnectionControl();

		void run();
		void closeConnection(ConnectionData* connData) const;

		friend ostream& operator<<(ostream&, const ServerConnectionControl&);

	private:
		int initWinSock();
		void initAddressData();
		void listenForConnections();
		SOCKET* findAvailableSocket();
		void processNewConnection();

		SOCKADDR_IN addressData;
		SOCKET listeningSocket;
		SOCKET connectionSocket;

		SOCKET* connections; // To hold all connection sockets
		int connCount; // Number of connected clients

		pthread_mutex_t findConnectionLock;
	};

} /* namespace Tom_F */

#endif /* SERVERCONNECTIONCONTROL_H_ */
