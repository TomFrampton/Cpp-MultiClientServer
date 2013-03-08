/*
 * DatabaseException.cpp
 *
 *  Created on: 6 Mar 2013
 *      Author: Tom
 */

#include "DatabaseException.h"

namespace Tom_F
{
	namespace Exception
	{
		DatabaseException::DatabaseException() throw():
		explanation("Database error")
		{
		}

		DatabaseException::DatabaseException(string explanation) throw() :
		explanation(explanation)
		{
		}

		DatabaseException::~DatabaseException() throw()
		{
		}

		string DatabaseException::getExplanation() const
		{
			return explanation;
		}

	} /* namespace Exception */

} /* namespace Tom_F */
