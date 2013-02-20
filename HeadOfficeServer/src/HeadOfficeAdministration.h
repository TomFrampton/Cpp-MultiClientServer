/*
 * HeadOfficeAdministration.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef HEADOFFICEADMINISTRATION_H_
#define HEADOFFICEADMINISTRATION_H_

#define FAIL -1

namespace Tom_F
{
	class Guest;

	class HeadOfficeAdministration
	{
	public:
		HeadOfficeAdministration();
		virtual ~HeadOfficeAdministration();

		int enrolMember(const Guest& newMember) const;
		bool logMemberStats(/*Stat obj*/);
	};

} /* namespace Tom_F */

#endif /* HEADOFFICEADMINISTRATION_H_ */
