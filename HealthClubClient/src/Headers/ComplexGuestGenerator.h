/*
 * ComplexGuestGenerator.h
 *
 *  Created on: 25 Feb 2013
 *      Author: Tom
 */

#ifndef COMPLEXGUESTGENERATOR_H_
#define COMPLEXGUESTGENERATOR_H_

#include <string>

#include "GuestGeneratorIF.h"

using std::string;

namespace Tom_F
{
	class ComplexGuestGenerator : public GuestGeneratorIF
	{
	public:
		ComplexGuestGenerator();
		virtual ~ComplexGuestGenerator();

		Guest generateGuest() const;

	};

} /* namespace Tom_F */

#endif /* COMPLEXGUESTGENERATOR_H_ */
