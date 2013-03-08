/*
 * HeadOfficeAdmin.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef HEADOFFICEADMIN_H_
#define HEADOFFICEADMIN_H_

#include "Guest.h"
#include "HealthData.h"
#include "Person.h"
#include "TrainingMeeting.h"
#include "SimulationData.h"
#include "DBControl.h"

namespace Tom_F
{
	class UserInterfaceIF;

	class HeadOfficeAdmin
	{
	public:
		HeadOfficeAdmin();
		HeadOfficeAdmin(DBControlIF* db, UserInterfaceIF* ui);
		virtual ~HeadOfficeAdmin();

		int registerHealthClub() const;
		int hireEmployee(const Person& toHire, string position, int healthClubID) const;
		int enrolMember(const Guest& newMember, int healthClubID) const;
		int logHealthData(const HealthData& data) const;
		HealthData getLastHealthLog(int membershipID) const;
		int logTrainingMeeting(const TrainingMeeting& meeting) const;
		SimulationData getSimulationData(int healthClubID) const;

	private:
		DBControlIF* db;
		UserInterfaceIF* userInterface;
	};

} /* namespace Tom_F */

#endif /* HEADOFFICEADMIN_H_ */
