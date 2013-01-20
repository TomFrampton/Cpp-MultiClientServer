/*
 * ServerControl.cpp
 *
 *  Created on: 12 Jan 2013
 *      Author: Tom
 */

#include <pthread.h> // POSIX threads
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "ServerControl.h"
#include "ConnInfo.h"

using namespace std;

void* newConnectionThread(void*);

ServerControl::ServerControl() : connections((SOCKET*)calloc(MAX_CONN, sizeof(SOCKET))),
									connCount(0){
	// TODO Auto-generated constructor stub
}

ServerControl::~ServerControl() {
	// TODO Auto-generated destructor stub
	free(connections);
}

int ServerControl::run(){
	// Start WinSock
	if(initWinSock() != 0){
		MessageBoxA(NULL, "WinSock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);

	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKET connectSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Set values for addr struct
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(CONN_PORT);

	// Bind listening socket and test for error
	if(bind(listenSock, (SOCKADDR*)&addr, addrLen) == SOCKET_ERROR){
		// Enter error code
		printf("bind error %ld", static_cast<long>( WSAGetLastError() ) );
		WSACleanup();
		return false;
	}

	// Listen for connections and test for error
	if(listen(listenSock, SOMAXCONN) == SOCKET_ERROR){
		// Enter error code
		printf("listen error %ld", static_cast<long>( WSAGetLastError() ) );
		WSACleanup();
		return false;
	}

	cout << "Listening" << endl;
	// Listen in an infinite loop
	for(;;Sleep(10)){
		connectSock = accept(listenSock, (SOCKADDR*)&addr, &addrLen);
		if(connectSock < 0){
			printf("Accept Error %ld ", static_cast<long>(WSAGetLastError()));
			WSACleanup();
			return false;
		}
		else {
			// Find a socket for this connection
			SOCKET* yourSocket = findAvailableSlot();
			// Test if a slot was found
			if(yourSocket != 0){
				*yourSocket = connectSock;

				// When we start a new thread we will pass the address of a struct containing a pointer
				// to the socket it will use and a pointer to the ServerControl object(this). The thread
				// function will copy the information passed to it's own variables. Before this happens we
				// must not leave this block otherwise the struct will go out of scope. So at end of block wait,
				// until thread signals it has copied the information.

				pthread_mutex_t connInfoCopyMutex;
				pthread_cond_t connInfoCopyCond;
				pthread_mutex_init(&connInfoCopyMutex, NULL);
				pthread_cond_init(&connInfoCopyCond, NULL);

				ConnInfo connInfo = {this, yourSocket, connInfoCopyCond}; // struct containing connection info

				pthread_t connectionHandler;
				pthread_create(&connectionHandler, NULL, newConnectionThread, &connInfo);
				pthread_cond_wait(&connInfoCopyCond, &connInfoCopyMutex); // Wait for signal from new thread
			}
			else{
				cout << "Max connections reached" << endl;
			}
		}
	}
	return 0;
}

int ServerControl::initWinSock(){
	WSAData wsa;
	WORD dllVersion = MAKEWORD(2,1);
	return (WSAStartup(dllVersion, &wsa));
}

SOCKET* ServerControl::findAvailableSlot(){
	// For the entire socket array
	for(int i = 0; i < MAX_CONN; i++){
		if(connections[i] == 0){
			// Return first free slot
			return &connections[i];
		}
	}
	// No slots available.
	return NULL;
}

void ServerControl::processClosedConnection(SOCKET* finishedSocket){
	closesocket(*finishedSocket);
	*finishedSocket = 0;
}

ostream& operator<<(ostream& os, const ServerControl& sc){
	for(int i = 0; i < 10; i++){
		cout << "Socket " << setw(2) << i << ": ";
		if(sc.connections[i] == 0){
			cout << "No connection";
		}
		else{
			cout << "Connection";
		}
		cout << "\n";
	}
	return os;
}

