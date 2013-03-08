/*
 * TrainingMeeting.cpp
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#include "TrainingMeeting.h"

namespace Tom_F
{
	TrainingMeeting::TrainingMeeting() :
	membershipID(0),
	employeeID(0),
	waitingTime(0),
	meetingType("PRE")
	{
	}

	TrainingMeeting::TrainingMeeting(const TrainingMeeting& toCopy) :
	membershipID(toCopy.getMembershipID()),
	employeeID(toCopy.getEmployeeID()),
	waitingTime(toCopy.getWaitingTime()),
	meetingType(toCopy.getMeetingType())
	{
	}

	TrainingMeeting::TrainingMeeting(int membershipID, int employeeID, int waitingTime, string meetingType) :
	membershipID(membershipID),
	employeeID(employeeID),
	waitingTime(waitingTime)
	{
		setMeetingType(meetingType);
	}

	TrainingMeeting::~TrainingMeeting()
	{
	}


	void TrainingMeeting::setMeetingType(string meetingType)
	{
		if(meetingType == "PRE" || meetingType == "POST")
		{
			this->meetingType = meetingType;
		}
		else
		{
			meetingType = "PRE";
		}
	}

	int TrainingMeeting::getMembershipID() const
	{
		return membershipID;
	}

	int TrainingMeeting::getEmployeeID() const
	{
		return employeeID;
	}

	int TrainingMeeting::getWaitingTime() const
	{
		return waitingTime;
	}

	string TrainingMeeting::getMeetingType() const
	{
		return meetingType;
	}

} /* namespace Tom_F */
