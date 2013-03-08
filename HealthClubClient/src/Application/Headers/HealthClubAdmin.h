/*
 * HealthClubAdmin.h
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#ifndef HEALTHCLUBADMIN_H_
#define HEALTHCLUBADMIN_H_

#include "ClientMessenger.h"
#include "UserInterfaceIF.h"
#include "PersonGenerator.h"
#include "Guest.h"
#include "Member.h"
#include "TrainingMeeting.h"
#include "TrainerQueue.h"
#include "SimulationData.h"

namespace Tom_F
{
	class HealthClubAdmin
	{
	public:
		HealthClubAdmin();
		HealthClubAdmin(ClientMessenger* messenger, UserInterfaceIF* ui);
		virtual ~HealthClubAdmin();

		TrainerQueue setupHealthClub(PersonGenerator& personGen, int trainerCount);
		Member enrolMember(const Guest& newMember);
		bool logHealthData(const Member& trainee, const HealthData& data, bool hasExercised);
		bool logTrainingMeeting(const TrainingMeeting& meeting, const Member& trainee);
		SimulationData  getSimulationData();

	private:
		ClientMessenger* messenger;
		UserInterfaceIF* userInterface;
		int healthClubID;
	};

} /* namespace Tom_F */

#endif /* HEALTHCLUBADMIN_H_ */
