/*
 * InvalidMemberException.cpp
 *
 *  Created on: 26 Feb 2013
 *      Author: Tom
 */

#include <exception>
#include "InvalidMemberException.h"

namespace Tom_F
{
	namespace Exception
	{
		InvalidMemberException::InvalidMemberException() :
		membershipID(0)
		{
		}

		InvalidMemberException::InvalidMemberException(int membershipID, string explanation) :
		membershipID(membershipID),
		explanation(explanation)
		{
		}

		InvalidMemberException::~InvalidMemberException() throw()
		{
		}

		int InvalidMemberException::getMembershipID() const
		{
			return membershipID;
		}

		string InvalidMemberException::getExplanation() const
		{
			return explanation;
		}

	} /* namespace Exceptions */

} /* namespace Tom_F */
