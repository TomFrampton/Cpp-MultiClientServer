/*
 * ClientControl.cpp
 *
 *  Created on: 13 Jan 2013
 *      Author: Tom
 */
#include <WinSock2.h> // For sockets
#include <Windows.h>
#include <pthread.h> // POSIX threads
#include <iostream>

#include "ClientControl.h"

using namespace std;

#define CONN_PORT 8000
#define BUF_SIZE 4096 // Block size
#define IP_ADDRESS "127.0.0.1"

ClientControl::ClientControl() {
}

ClientControl::~ClientControl() {
	// TODO Auto-generated destructor stub
}

int ClientControl::connectToHeadOffice(){
	connectSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(connect(connectSock, (SOCKADDR*)&addr, addrLen) != 0){
		MessageBoxA(NULL, "Could not connect to server", "Error", MB_OK | MB_ICONERROR);
		return 1;
	}
	else{
		cout << "Connected" << endl;
		return 0;
	}
}

void ClientControl::disconnect(){
	closesocket(connectSock);
}

int ClientControl::run(){
	// Start WinSock
	if(initWinSock() != 0){
		MessageBoxA(NULL, "WinSock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	addrLen = sizeof(addr);

	addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(CONN_PORT);

	connectToHeadOffice();

	for(;;Sleep(10)){
		char* buffer = new char[BUF_SIZE];
		ZeroMemory(buffer, BUF_SIZE);
		cin.getline(buffer, BUF_SIZE);
		send(connectSock, buffer, BUF_SIZE, 0);
		delete[] buffer;
	}

	return 0;
}

int ClientControl::initWinSock(){
	WSAData wsa;
	WORD dllVersion = MAKEWORD(2,1);
	return (WSAStartup(dllVersion, &wsa));
}

