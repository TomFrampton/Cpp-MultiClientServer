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
#include <Windows.h> // For Sleep()
#include <pthread.h> // For POSIX threads
#include <iostream>
#include <sstream>
#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>

#include "ConnectionHandler.h"
#include "HeadOfficeAdmin.h"

using std::ostream; // To overload the << operator
using std::stringstream;
using std::vector;
using boost::shared_ptr;

#define CONN_PORT 8066 // Server will connect on port 8000
#define BUF_SIZE 4096 // The server will accept packet sized char*

namespace Tom_F
{
	class ConnectionData;
	class HeadOfficeAdmin;

	class ServerConnectionControl
	{
	public:
		ServerConnectionControl();
		ServerConnectionControl(const HeadOfficeAdmin* admin);
		virtual ~ServerConnectionControl();

		void run(int maxConnections);

		stringstream toString();
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
		const HeadOfficeAdmin* const admin;

		int maxConnection; // Max number of connections
		SOCKET* connections; // To hold all connection sockets
		vector<shared_ptr<ConnectionHandler> > handlers;

		pthread_mutex_t findConnectionLock;
	};

} /* namespace Tom_F */

#endif /* SERVERCONNECTIONCONTROL_H_ */
