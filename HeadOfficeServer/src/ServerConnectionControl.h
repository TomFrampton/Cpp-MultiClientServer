/*
 * ServerConnectionControl.h
 *
 *  Created on: 	9 Feb 2013
 *  Author: 		Tom Frampton
 */

#ifndef SERVERCONNECTIONCONTROL_H_
#define SERVERCONNECTIONCONTROL_H_

#include <WinSock2.h> // For sockets
#include <Windows.h>

using std::ostream;

#define CONN_PORT 8000
#define BUF_SIZE 4096 // Block size

namespace Tom_F {

class ServerConnectionControl {
public:
	ServerConnectionControl();
	virtual ~ServerConnectionControl();
	int run();
	friend ostream& operator<<(ostream&, const ServerConnectionControl&);

private:
	int initWinSock();

};

} /* namespace Tom_F */
#endif /* SERVERCONNECTIONCONTROL_H_ */
