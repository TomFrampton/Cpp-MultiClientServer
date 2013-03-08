/*
 * GuestGenerator.h
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#ifndef GUESTGENERATOR_H_
#define GUESTGENERATOR_H_

#include "PersonGenerator.h"
#include "Guest.h"

namespace Tom_F {

class GuestGenerator
{
public:
	GuestGenerator(PersonGenerator& personGen);
	virtual ~GuestGenerator();

	Guest generateGuest();

private:
	PersonGenerator& personGen;
};

} /* namespace Tom_F */
#endif /* GUESTGENERATOR_H_ */
