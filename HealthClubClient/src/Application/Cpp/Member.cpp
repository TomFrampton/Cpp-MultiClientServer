/*
 * Member.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include <sstream>
#include "Member.h"

using std::stringstream;

namespace Tom_F
{
	Member::Member() :
	Customer(),
	membershipID(0)
	{
	}

	Member::Member(const Member& toCopy) :
	Customer(toCopy),
	membershipID(toCopy.membershipID)
	{
	}

	Member::Member(int membershipID, const Guest& enrolled) :
	Customer(enrolled),
	membershipID(membershipID)
	{
	}

	Member::~Member()
	{
	}

	void Member::setMembershipID(int id)
	{
		membershipID = id;
	}

	int Member::getMembershipID() const
	{
		return membershipID;
	}

	string Member::toString() const
	{
		stringstream ss;
		ss << *this;
		return ss.str();

	}

	ostream& operator<<(ostream& os, const Member& member)
		{
			os << static_cast<const Customer&>(member);
			os << "(" << member.membershipID << ")";
			return os;
		}

} /* namespace Tom_F */
