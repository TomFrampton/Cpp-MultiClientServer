/*
 * ServerControl.h
 *
 *  Created on: 12 Jan 2013
 *      Author: Tom Frampton
 *
 *  Revisions:
 *  	12 Jan 2013 - Initial creation
 */

#ifndef SERVERCONTROL_H_
#define SERVERCONTROL_H_

#include <WinSock2.h> // For sockets
#include <Windows.h>

using std::ostream;

#define CONN_PORT 8000
#define BUF_SIZE 4096 // Block size
#define MAX_CONN 64

class ServerControl {
public:
	ServerControl();
	virtual ~ServerControl();

	int run();

	friend ostream& operator<<(ostream&, const ServerControl&);

private:
	int initWinSock();
	SOCKET* findAvailableSlot();
	void processClosedConnection(SOCKET*);
	friend void* newConnectionThread(void*);

	SOCKET* connections; // To hold sockets
	int connCount; // Number of connected clients
};

#endif /* SERVERCONTROL_H_ */
