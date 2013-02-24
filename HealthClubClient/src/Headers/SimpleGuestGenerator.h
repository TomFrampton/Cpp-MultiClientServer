/*
 * SimpleGuestGenerator.h
 *
 *  Created on: 24 Feb 2013
 *      Author: Tom
 */

#ifndef SIMPLEGUESTGENERATOR_H_
#define SIMPLEGUESTGENERATOR_H_

#include "GuestGeneratorIF.h"
#include "Guest.h"

namespace Tom_F {

class SimpleGuestGenerator : public GuestGeneratorIF
{
	public:
		SimpleGuestGenerator();
		virtual ~SimpleGuestGenerator();

		Guest generateGuest();
	};

} /* namespace Tom_F */
#endif /* SIMPLEGUESTGENERATOR_H_ */
