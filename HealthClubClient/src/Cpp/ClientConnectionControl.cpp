/*
 * @file 	 ClientConnectionControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */
#include <iostream>
#include "ClientConnectionControl.h"

namespace Tom_F
{

	ClientConnectionControl::ClientConnectionControl()
	{
		// TODO Auto-generated constructor stub
	}

	ClientConnectionControl::~ClientConnectionControl()
	{
		// TODO Auto-generated destructor stub
	}

	void ClientConnectionControl::connectToHeadOffice()
	{
		// Start WinSock
		if(initWinSock() != 0){
			// throw winsock startup exception
		}

		SOCKADDR_IN addressData = initAddressData();
		int addressLength = sizeof(addressData);

		if(connect(connectionSocket, (SOCKADDR*)&addressData, addressLength) != 0)
		{
			// throw connection exception
		}
		else
		{
		}
	}

	void ClientConnectionControl::disconnect()
	{
		closesocket(connectionSocket);
		WSACleanup();
	}

	void ClientConnectionControl::sendMessage(string message) const
	{
		const char* cMessage = message.c_str();
		send(connectionSocket, cMessage, strlen(cMessage) + 1, 0);
	}

	string ClientConnectionControl::listenForMessage() const
	{
		char recvMsg[BUF_SIZE];
		recv(connectionSocket, recvMsg, BUF_SIZE, 0);
		return string(recvMsg);
	}

	const SOCKET* ClientConnectionControl::getConnectionSocket() const
	{
		return &connectionSocket;
	}


	int ClientConnectionControl::initWinSock()
	{
		WSAData wsa;
		WORD dllVersion = MAKEWORD(2,1);
		return (WSAStartup(dllVersion, &wsa));
	}

	SOCKADDR_IN ClientConnectionControl::initAddressData()
	{
		SOCKADDR_IN addressData;

		connectionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		// Set values for the address data struct
		addressData.sin_addr.s_addr = inet_addr(IP_ADDRESS);
		addressData.sin_family = AF_INET;
		addressData.sin_port = htons(CONN_PORT);

		return addressData;
	}

}
