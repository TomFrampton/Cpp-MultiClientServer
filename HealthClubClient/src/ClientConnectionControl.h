/*
 * ClientConnectionControl.h
 *
 *  Created on: 9 Feb 2013
 *      Author: Tom
 */

#ifndef CLIENTCONNECTIONCONTROL_H_
#define CLIENTCONNECTIONCONTROL_H_

#include <WinSock2.h> // For sockets
#include <Windows.h>

#define IP_ADDRESS "127.0.0.1"
#define CONN_PORT 8000

namespace Tom_F {

class ClientConnectionControl {
public:
	ClientConnectionControl();
	virtual ~ClientConnectionControl();
	int connectToHeadOffice();
	void disconnect();
	void sendMessage(char* message);

private:
	int initWinSock();

	SOCKET connectSock;
	SOCKADDR_IN addr;
	int addrLen;
};

} /* namespace Tom_F */
#endif /* CLIENTCONNECTIONCONTROL_H_ */
