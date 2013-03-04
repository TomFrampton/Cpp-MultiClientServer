/*
 * ConnectionHandler.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef CONNECTIONHANDLER_H_
#define CONNECTIONHANDLER_H_

#include <string>

#include "HeadOfficeAdmin.h"
#include "Thread.h"

using std::string;

namespace Tom_F {

	class ConnectionHandler : public Thread
	{
	public:
		ConnectionHandler();
		ConnectionHandler(const HeadOfficeAdmin* admin, SOCKET* connection, int maxBufSize);
		virtual ~ConnectionHandler();

		void sendMessage(string message) const;
		string listenForMessage() const;

	protected:
		void threadStart();

	private:
		const HeadOfficeAdmin* admin;
		SOCKET* connection;
		int maxBufferSize;
	};

} /* namespace Tom_F */
#endif /* CONNECTIONHANDLER_H_ */
