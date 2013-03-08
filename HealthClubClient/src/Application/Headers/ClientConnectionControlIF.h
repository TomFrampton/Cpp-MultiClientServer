/*
 * ClientConnectionControlIF.h
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
 */

#ifndef CLIENTCONNECTIONCONTROLIF_H_
#define CLIENTCONNECTIONCONTROLIF_H_

#include <string>

using std::string;

namespace Tom_F
{
	class ClientConnectionControlIF
	{
	public:
		ClientConnectionControlIF();
		virtual ~ClientConnectionControlIF() = 0;

		virtual void connectToHeadOffice() = 0;
		virtual void disconnect() = 0;
		virtual void sendMessage(string message) const = 0;
		virtual string listenForMessage() const = 0;
	};

} /* namespace Tom_F */

#endif /* CLIENTCONNECTIONCONTROLIF_H_ */
