/*
 * @file 	 ClientConnectionControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include "ClientConnectionControl.h"

namespace Tom_F {

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
			while(true){}
		}
	}

	void ClientConnectionControl::disconnect()
	{
		closesocket(connectionSocket);
		WSACleanup();
	}

	void ClientConnectionControl::sendMessage(char* message)
	{
		int bufferSize = sizeof(message) / sizeof(char);
		char buffer[bufferSize];
		ZeroMemory(buffer, bufferSize);
		send(connectionSocket, buffer, bufferSize, 0);
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
		int addressLength = sizeof(addressData);

		connectionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		// Set values for the address data struct
		addressData.sin_addr.s_addr = inet_addr(IP_ADDRESS);
		addressData.sin_family = AF_INET;
		addressData.sin_port = htons(CONN_PORT);

		return addressData;
	}

}
