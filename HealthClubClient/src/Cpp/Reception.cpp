/*
 * Reception.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include "Reception.h"
using Tom_F::Guest;
namespace Tom_F {

	Reception::Reception(const ClientMessenger* const messenger) :
	messenger(messenger)
	{
		// TODO Auto-generated constructor stub
	}

	Reception::~Reception()
	{
		// TODO Auto-generated destructor stub
	}

	void Reception::arrive(Guest arrival)
	{
		messenger->enrolMember(arrival);
	}



} /* namespace Tom_F */
