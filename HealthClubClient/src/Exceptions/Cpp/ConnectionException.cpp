/*
 * ConnectionException.cpp
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
 */

#include "ConnectionException.h"

namespace Tom_F
{
	namespace Exception
	{
		ConnectionException::ConnectionException() throw ():
		explanation("Connection failure")
		{
		}

		ConnectionException::ConnectionException(string explanation) throw() :
		explanation(explanation)
		{
		}

		ConnectionException::~ConnectionException() throw()
		{
		}

		string ConnectionException::getExplanation() const
		{
			return explanation;
		}

	} /* namespace Exception */

} /* namespace Tom_F */
