/*
 * UserInterfaceIF.h
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#ifndef USERINTERFACEIF_H_
#define USERINTERFACEIF_H_

#include <string>

using std::string;

namespace Tom_F {

class UserInterfaceIF {
public:
	UserInterfaceIF();
	virtual ~UserInterfaceIF() = 0;

	virtual void printOutput(string outputMessage) = 0;

};

} /* namespace Tom_F */
#endif /* USERINTERFACEIF_H_ */
