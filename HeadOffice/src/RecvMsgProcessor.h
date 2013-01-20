/*
 * RecvMsgProcessor.h
 *
 *  Created on: 12 Jan 2013
 *      Author: Tom
 */


// TODO could make SINGLETON

#ifndef RECVMSGPROCESSOR_H_
#define RECVMSGPROCESSOR_H_

#include <string>

using std::string;

class RecvMsgProcessor {
public:
	static RecvMsgProcessor& getInstance(); // Calls the constructor
	virtual ~RecvMsgProcessor();

	void processMsg(string msg);

private:
	RecvMsgProcessor();
};

#endif /* RECVMSGPROCESSOR_H_ */
