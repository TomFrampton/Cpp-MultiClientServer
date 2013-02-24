/*
 * GuestGeneratorIF.h
 *
 *  Created on: 24 Feb 2013
 *      Author: Tom
 */

#ifndef GUESTGENERATORIF_H_
#define GUESTGENERATORIF_H_

#include "Guest.h"

namespace Tom_F
{
	class GuestGeneratorIF {
	public:
		GuestGeneratorIF();
		virtual ~GuestGeneratorIF() = 0;

		virtual Guest generateGuest() = 0;


	};

} /* namespace Tom_F */

#endif /* GUESTGENERATORIF_H_ */
