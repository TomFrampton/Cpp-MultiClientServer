/*
 * HealthClubAdmin.cpp
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#include <vector>

#include "CommunicationException.h"
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

	/**
	 * Constructor.
	 * @param   ui         The user interface object to print output messages to
	 * @param   messenger  The messenger object to use to communicate with the server
	 */
	HealthClubAdmin::HealthClubAdmin(ClientMessenger* messenger, UserInterfaceIF* ui) :
	messenger(messenger),
	userInterface(ui),
	healthClubID(0) // Initialize to 0 as we haven't registered the health club yet
	{
	}

	HealthClubAdmin::~HealthClubAdmin()
	{
	}

	TrainerQueue HealthClubAdmin::setupHealthClub(PersonGenerator& personGen, int trainerCount)
	{
		userInterface->printOutput("\nRegistering health club...");
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
				throw Exception::CommunicationException("Trainer registration failed");
			}
		}
		userInterface->printOutput("\n");
		return TrainerQueue(trainersToUse);
	}

	Member HealthClubAdmin::enrolMember(const Guest& newMember)
	{
		int memberID = messenger->enrolMember(newMember, healthClubID);

		if(memberID > 0)
		{
			Member enrolled(memberID, newMember);
			userInterface->printOutput(enrolled.toString() + " - ENROLLED");
			return enrolled;
		}
		else
		{
			userInterface->printOutput(newMember.toString() + " - ENROL FAILED");
			throw Exception::CommunicationException("Member enrol failed");
		}
	}

	bool HealthClubAdmin::logHealthData(const Member& trainee, const HealthData& data, bool hasExercised)
	{
		if(hasExercised)
		{
			HealthData oldData = messenger->getLastHealthLog(trainee.getMembershipID());
			userInterface->printOutput(trainee.toString() + " - "+ data.toProgressString(oldData));
		}

		bool success = messenger->logHealthData(data);

		if(!hasExercised)
		{
			if(success)
			{
				HealthCalculator healthCalc;
				userInterface->printOutput(trainee.toString() + " - "
							   "" + healthCalc.getHealthString(data, trainee.getGender()) + ""
							   " - Started training...");
			}
			else
			{
				userInterface->printOutput(trainee.toString() + " - DATA LOGGING FAILED");
			}
		}

		return success;
	}

	bool HealthClubAdmin::logTrainingMeeting(const TrainingMeeting& meeting, const Member& trainee)
	{
		bool success = messenger->logTrainingMeeting(meeting);

		if(success)
		{
			if(meeting.getMeetingType() == "PRE")
			{
				userInterface->printOutput(trainee.toString() + " - planning a training program with Trainer "
										   "" + StringIntConverter::intToString(meeting.getEmployeeID()));
			}
		}
		else
		{
			userInterface->printOutput(trainee.toString() +" - MEETING LOGGING FAILED");
		}
		return success;
	}

	SimulationData  HealthClubAdmin::getSimulationData()
	{
		userInterface->printOutput("\nSimulation finished. Fetching data...");
		return messenger->getSimulationData(healthClubID);
	}

} /* namespace Tom_F */
