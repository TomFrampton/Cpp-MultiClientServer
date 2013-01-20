/*
 * RecvMsgProcessor.cpp
 *
 *  Created on: 12 Jan 2013
 *      Author: Tom
 */

#include <iostream>
#include "RecvMsgProcessor.h"

using namespace std;

RecvMsgProcessor::RecvMsgProcessor() {
	// TODO Auto-generated constructor stub
}

RecvMsgProcessor::~RecvMsgProcessor() {
	// TODO Auto-generated destructor stub
}

RecvMsgProcessor& RecvMsgProcessor::getInstance(){
	static RecvMsgProcessor instance;
	return instance;
}

void RecvMsgProcessor::processMsg(string msg){
	if(msg == "talk"){
		cout << "hello" << endl;
	}
	else{
		cout << "not a valid message" << endl;
	}
}

