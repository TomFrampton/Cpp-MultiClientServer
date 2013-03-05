/*
 * HealthClubAdmin.cpp
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#include <vector>

#include "Exceptions/EnrolException.h"
#include "HealthCalculator.h"
#include "StringIntConverter.h"
#include "HealthClubAdmin.h"

using std::vector;

namespace Tom_F
{
	HealthClubAdmin::HealthClubAdmin() :
	messenger(NULL),
	userInterface(NULL),
	healthClubID(0)
	{
	}

	HealthClubAdmin::HealthClubAdmin(ClientMessenger* messenger, UserInterfaceIF* ui) :
	messenger(messenger),
	userInterface(ui),
	healthClubID(0)
	{
	}

	HealthClubAdmin::~HealthClubAdmin()
	{
	}

	TrainerQueue HealthClubAdmin::setupHealthClub(PersonGenerator& personGen, int trainerCount)
	{
		userInterface->printOutput("Registering health club...");
		healthClubID = messenger->registerHealthClub();

		if(healthClubID)
		{
			userInterface->printOutput("Health Club - REGISTERED \n");
		}
		else
		{
			userInterface->printOutput("Health Club registration failed \n");
		}

		userInterface->printOutput("Registering trainers...");
		vector<Trainer> trainersToUse;
		for(int i = 0; i < trainerCount; i++)
		{
			Person newTrainer = personGen.generatePerson();
			int employeeID = messenger->hireTrainer(newTrainer, healthClubID);

			if(employeeID > 0)
			{
				trainersToUse.push_back(Trainer(Employee(employeeID, newTrainer)));
				userInterface->printOutput("Trainer - REGISTERED");
			}
			else
			{
				userInterface->printOutput("Trainer - REGISTRATION FAILED");
			}
		}
		return TrainerQueue(trainersToUse);
	}

	Member HealthClubAdmin::enrolMember(const Guest& newMember)
	{
		int memberID = messenger->enrolMember(newMember, healthClubID);

		if(memberID > 0)
		{
			Member enrolled(memberID, newMember);
			userInterface->printOutput(newMember.toString() + " - ENROLLED");
			return enrolled;
		}
		else
		{
			userInterface->printOutput(newMember.toString() + " - ENROL FAILED");
			//throw EnrolException();
		}
	}

	bool HealthClubAdmin::logHealthData(const Member& trainee, const HealthData& data)
	{
		bool success = messenger->logHealthData(data);

		if(success)
		{
			HealthCalculator healthCalc;
			userInterface->printOutput("Health data logged for member "
						   "" + StringIntConverter::intToString(trainee.getMembershipID()) + " - "
						   "" + healthCalc.getHealthString(data, trainee.getGender()));
		}
		else
		{
			userInterface->printOutput(trainee.toString() + " - DATA LOGGING FAILED");
		}
		return success;
	}

	bool HealthClubAdmin::logTrainingMeeting(const TrainingMeeting& meeting)
	{
		bool success = messenger->logTrainingMeeting(meeting);

		if(success)
		{
			//userInterface->printOutput(meeting.toString() + " - LOGGED");
		}
		else
		{
			//userInterface->printOutput(meeting.toString() + " - LOGGING FAILED");
		}
		return success;
	}

	SimulationData  HealthClubAdmin::getSimulationData()
	{
		userInterface->printOutput("Simulation finished. Fetching data...");
		return messenger->getSimulationData(healthClubID);
	}

} /* namespace Tom_F */
