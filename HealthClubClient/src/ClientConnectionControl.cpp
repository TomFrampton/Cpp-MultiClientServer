/*
 * ClientConnectionControl.cpp
 *
 *  Created on: 9 Feb 2013
 *      Author: Tom
 */

#include "ClientConnectionControl.h"

namespace Tom_F {

ClientConnectionControl::ClientConnectionControl() {
	// TODO Auto-generated constructor stub

}

ClientConnectionControl::~ClientConnectionControl() {
	// TODO Auto-generated destructor stub
}

int ClientConnectionControl::connectToHeadOffice(){
	// Start WinSock
	if(initWinSock() != 0){
		// throw winsock startup excepti
		exit(1);
	}

	addrLen = sizeof(addr);

	addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(CONN_PORT);

	connectSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(connect(connectSock, (SOCKADDR*)&addr, addrLen) != 0){
		// throw connection exception
		return 1;
	}
	else{
		// cout connected
		return 0;
	}
}

void ClientConnectionControl::disconnect(){
	closesocket(connectSock);
	WSACleanup();
}

void ClientConnectionControl::sendMessage(char* message){
	int bufferSize = sizeof(message) / sizeof(char);
	char buffer[bufferSize];
	ZeroMemory(buffer, bufferSize);
	send(connectSock, buffer, bufferSize, 0);
}

int ClientConnectionControl::initWinSock(){
	WSAData wsa;
	WORD dllVersion = MAKEWORD(2,1);
	return (WSAStartup(dllVersion, &wsa));
}

}
