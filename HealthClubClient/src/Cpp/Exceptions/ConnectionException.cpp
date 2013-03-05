/*
 * ConnectionException.cpp
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
 */

#include "Exceptions/ConnectionException.h"

namespace Tom_F
{
	namespace Exception
	{
		ConnectionException::ConnectionException() :
		explanation("Connection failure")
		{
		}

		ConnectionException::ConnectionException(string explanation) :
		explanation(explanation)
		{
		}

		ConnectionException::~ConnectionException()
		{
		}

		string ConnectionException::getExplanation() const
		{
			return explanation;
		}

	} /* namespace Exception */

} /* namespace Tom_F */
