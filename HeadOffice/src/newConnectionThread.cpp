
#include <iostream>
#include <WinSock2.h> // For sockets
#include <Windows.h>
#include <pthread.h> // POSIX threads
#include <cstdlib>

#include "ConnInfo.h"
#include "RecvMsgProcessor.h"

using namespace std;

void* newConnectionThread(void* arg){

	ConnInfo connInfo = *(ConnInfo*)arg;
	pthread_cond_broadcast(&connInfo.thisCopyCond);

	cout << *connInfo.server << endl;

	char* recvMsg = new char[BUF_SIZE];
	ZeroMemory(recvMsg, BUF_SIZE);

	RecvMsgProcessor* msgProcessor = &RecvMsgProcessor::getInstance();

	for(;;Sleep(10)){
		int bytesRecv = recv(*connInfo.yourSocket, recvMsg, BUF_SIZE, 0);
		if(bytesRecv <= 0){
			cout << "Connection lost with client " << endl;
			connInfo.server->processClosedConnection(connInfo.yourSocket);
			break;
		}
		msgProcessor->processMsg(recvMsg);
	}

	delete[] recvMsg;
	cout << "\n" << *connInfo.server << endl;
	return 0;
}

