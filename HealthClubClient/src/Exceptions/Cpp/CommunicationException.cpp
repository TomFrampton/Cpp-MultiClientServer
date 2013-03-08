/*
 * CommunicationException.cpp
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
 */

#include "CommunicationException.h"

namespace Tom_F
{
	namespace Exception
	{
		CommunicationException::CommunicationException() throw() :
		explanation("Communication with server failure")
		{
		}

		CommunicationException::CommunicationException(string explanation) throw():
		explanation(explanation)
		{
		}

		CommunicationException::~CommunicationException() throw()
		{
		}

		string CommunicationException::getExplanation() const
		{
			return explanation;
		}

	} /* namespace Exception */

} /* namespace Tom_F */
