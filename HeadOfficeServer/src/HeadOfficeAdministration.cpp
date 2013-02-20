/*
 * HeadOfficeAdministration.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */
#include "debug.h"
#include "MemberMapper.h"

#include "HeadOfficeAdministration.h"

namespace Tom_F
{

	HeadOfficeAdministration::HeadOfficeAdministration()
	{
		// TODO Auto-generated constructor stub

	}

	HeadOfficeAdministration::~HeadOfficeAdministration()
	{
		// TODO Auto-generated destructor stub
	}

	int HeadOfficeAdministration::enrolMember(const Guest& newMember) const
	{
		MemberMapper mapper;
		int result = mapper.addMemberToDatabase(newMember);

		if(result)
		{
			return result;
		}
		else
		{
			return FAIL;
		}
	}

	bool HeadOfficeAdministration::logMemberStats(/*Stat obj*/)
	{

	}

} /* namespace Tom_F */
