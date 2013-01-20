/*
 * ClientControl.h
 *
 *  Created on: 13 Jan 2013
 *      Author: Tom
 */

#ifndef CLIENTCONTROL_H_
#define CLIENTCONTROL_H_

#include <WinSock2.h> // For sockets
#include <Windows.h>

#define CONN_PORT 8000
#define BUF_SIZE 4096 // Block size

class ClientControl {
public:
	ClientControl();
	virtual ~ClientControl();

	int run();
	int connectToHeadOffice();
	void disconnect();

private:

	int initWinSock();

	SOCKET connectSock;
	SOCKADDR_IN addr;
	int addrLen;
};

#endif /* CLIENTCONTROL_H_ */
