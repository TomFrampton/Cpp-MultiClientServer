/*
 * CommunicationException.cpp
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
 */

#include "Exceptions/CommunicationException.h"

namespace Tom_F
{
	namespace Exception
	{
		CommunicationException::CommunicationException() :
		explanation("Communication with server failure")
		{
		}

		CommunicationException::CommunicationException(string explanation) :
		explanation(explanation)
		{
		}

		CommunicationException::~CommunicationException()
		{
		}

		string CommunicationException::getExplanation() const
		{
			return explanation;
		}

	} /* namespace Exception */

} /* namespace Tom_F */
