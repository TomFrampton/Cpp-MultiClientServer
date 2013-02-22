/*
 * Member.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include "Member.h"

namespace Tom_F
{
	Member::Member()
	{
		// TODO Auto-generated constructor stub
	}

	Member::Member(int memberNo) : membershipNo(memberNo)
	{

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
