/*
 * @file 	 ClientMessenger.h
 * @author	 Tom Frampton
 * @date 	 2013-02-14
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * Responsible for translating method calls into a Message object and serializing to a char*
 * to be send across the network.
 */

#ifndef CLIENTMESSENGER_H_
#define CLIENTMESSENGER_H_

#include <pthread.h>
#include <string.h>

#include "ClientConnectionControlIF.h"
#include "Guest.h"
#include "Member.h"
#include "Employee.h"
#include "HealthData.h"
#include "Trainer.h"
#include "TrainingMeeting.h"
#include "SimulationData.h"
#include "Serializer.h"

using std::string;

namespace Tom_F
{

	class ClientMessenger
	{
	public:
		ClientMessenger(const ClientConnectionControlIF* connectionControl);
		virtual ~ClientMessenger();

		int registerHealthClub();
		int hireTrainer(Person& hired, int healthClubID);
		int enrolMember(const Guest& newMember, int healthClubID);
		bool logHealthData(const HealthData& data);
		HealthData getLastHealthLog(int membershipID);
		bool logTrainingMeeting(const TrainingMeeting& meeting);
		SimulationData  getSimulationData(int healthClubID);

	private:
		Serializer serializer;
		const ClientConnectionControlIF* connectionControl;
		pthread_mutex_t messagingLock;

		int hireEmployee(Person& hired, string position, int healthClubID);

	};

} /* namespace Tom_F */

#endif /* CLIENTMESSENGER_H_ */
