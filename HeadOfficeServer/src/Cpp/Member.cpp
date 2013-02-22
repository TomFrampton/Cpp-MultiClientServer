/*
 * Member.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include "Member.h"

namespace Tom_F
{
	Member::Member() : membershipNo(0)
	{
		Person();
	}

	Member::Member(Member& toCopy) : membershipNo(toCopy.membershipNo)
	{
		Person();
	}

	Member::Member(int memberNo) : membershipNo(memberNo)
	{
		Person();
	}

	Member::~Member()
	{
		// TODO Auto-generated destructor stub
	}

	int Member::getMembershipNo() const
	{
		return membershipNo;
	}

} /* namespace Tom_F */
