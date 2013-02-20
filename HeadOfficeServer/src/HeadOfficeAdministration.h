/*
 * HeadOfficeAdministration.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef HEADOFFICEADMINISTRATION_H_
#define HEADOFFICEADMINISTRATION_H_

#include "Guest.h"

namespace Tom_F
{

	class HeadOfficeAdministration
	{
	public:
		HeadOfficeAdministration();
		virtual ~HeadOfficeAdministration();

		int enrolMember(Guest& newMember);
		bool logMemberStats(/*Stat obj*/);
	};

} /* namespace Tom_F */

#endif /* HEADOFFICEADMINISTRATION_H_ */
