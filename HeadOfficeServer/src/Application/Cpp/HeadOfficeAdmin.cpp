/*
 * HeadOfficeAdministration.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include "MemberMapper.h"
#include "HealthDataMapper.h"
#include "HealthClubMapper.h"
#include "EmployeeMapper.h"
#include "TrainingMeetingMapper.h"
#include "StringIntConverter.h"
#include "UserInterfaceIF.h"

#include "HeadOfficeAdmin.h"

#define SUCCESS 1
#define FAIL -1

namespace Tom_F
{

	HeadOfficeAdmin::HeadOfficeAdmin() :
	db(NULL),
	userInterface(NULL)
	{
	}

	HeadOfficeAdmin::HeadOfficeAdmin(DBControlIF* db, UserInterfaceIF* ui) :
	db(db),
	userInterface(ui)
	{
	}

	HeadOfficeAdmin::~HeadOfficeAdmin()
	{
	}

	int HeadOfficeAdmin::registerHealthClub() const
	{
		HealthClubMapper mapper;
		int healthClubID = mapper.addToDatabase(*db);

		if(healthClubID)
		{
			userInterface->printOutput("Health Club registered with ID "
									   "" + StringIntConverter::intToString(healthClubID));
			return healthClubID;
		}
		else
		{
			userInterface->printOutput("Health Club registration error");
			return FAIL;
		}
	}

	int HeadOfficeAdmin::hireEmployee(const Person& toHire, string position, int healthClubID) const
	{
		if(position != "TRAINER")
		{
			return FAIL;
		}

		EmployeeMapper mapper;
		int employeeID = mapper.addToDatabase(*db, toHire, position, healthClubID);

		if(employeeID)
		{
			userInterface->printOutput(toHire.toString() + " has been hired");
			return employeeID;
		}
		else
		{
			userInterface->printOutput("EMPLOYEE HIRING FAILED");
			return FAIL;
		}
	}

	int HeadOfficeAdmin::enrolMember(const Guest& newMember, int healthClubID) const
	{
		MemberMapper mapper;
		int membershipID = mapper.addToDatabase(*db, newMember, healthClubID);

		if(membershipID)
		{
			userInterface->printOutput(newMember.toString() + " - ENROLLED.");
			return membershipID;
		}
		else
		{
			userInterface->printOutput(newMember.toString() + " - ENROL ERROR.");
			return FAIL;
		}
	}

	int HeadOfficeAdmin::logHealthData(const HealthData& data) const
	{
		HealthDataMapper mapper;
		int result = mapper.addToDatabase(*db, data);

		if(result)
		{
			string memberID = StringIntConverter::intToString(data.getMembershipID());
			userInterface->printOutput("Health data added for Member " + memberID);
			return result;
		}
		else
		{
			userInterface->printOutput("HEALTH DATA LOGGING ERROR");
			return FAIL;
		}
	}

	HealthData HeadOfficeAdmin::getLastHealthLog(int membershipID) const
	{
		HealthDataMapper mapper;

		userInterface->printOutput("Fetching health statistics for Member "
				                   "" + StringIntConverter::intToString(membershipID));

		return mapper.getLastHealthLog(*db, membershipID);
	}

	int HeadOfficeAdmin::logTrainingMeeting(const TrainingMeeting& meeting) const
	{
		TrainingMeetingMapper mapper;

		if(mapper.addToDatabase(*db, meeting))
		{
			string memberID = StringIntConverter::intToString(meeting.getMembershipID());
			string trainerID = StringIntConverter::intToString(meeting.getEmployeeID());

			userInterface->printOutput("Training meeting logged between Member " + memberID + ""
					                   " and Trainer " + trainerID);
			return SUCCESS;
		}
		else
		{
			userInterface->printOutput("TRAINING MEETING LOGGING ERROR");
			return FAIL;
		}
	}

	SimulationData HeadOfficeAdmin::getSimulationData(int healthClubID) const
	{
		MemberMapper memberMapper;
		int enrolledCount = memberMapper.getMemberCount(*db, healthClubID);

		TrainingMeetingMapper trainingMapper;
		int averageWaitingTime = trainingMapper.getAverageWaitingTime(*db, healthClubID);

		userInterface->printOutput("\nSimulation for Health Club "
				                   "" + StringIntConverter::intToString(healthClubID) + ""
				                   " finished. Fetching data...\n");

		SimulationData data(enrolledCount, averageWaitingTime);
		return data;
	}

} /* namespace Tom_F */
