/*
 * TrainingMeetingMapper.cpp
 *
 *  Created on: 28 Feb 2013
 *      Author: Tom
 */

#include <DBControl.h>
#include <StringIntConverter.h>

#include "TrainingMeetingMapper.h"

namespace Tom_F
{
	TrainingMeetingMapper::TrainingMeetingMapper()
	{
		// TODO Auto-generated constructor stub

	}

	TrainingMeetingMapper::~TrainingMeetingMapper()
	{
		// TODO Auto-generated destructor stub
	}

	bool TrainingMeetingMapper::addToDatabase(DBControl& db, const TrainingMeeting& meeting) const
	{
		string SQL = "INSERT INTO trainingMeeting (membershipID, meetingTime, employeeID,"
												  "waitingTime, meetingType) VALUES"
				     "("
				        "" + StringIntConverter::intToString(meeting.getMembershipID()) + ","
				           " CURRENT_TIMESTAMP(), "
				        "" + StringIntConverter::intToString(meeting.getEmployeeID()) + ","
				        "" + StringIntConverter::intToString(meeting.getWaitingTime()) + ","
				        "'" + meeting.getMeetingType() + "'"
				     ");";

		int affectedRows = db.queryAffectedRows(SQL);

		return affectedRows == 1;
	}

	int TrainingMeetingMapper::getAverageWaitingTime(DBControl& db, int healthClubID) const
	{
		string SQL = "SELECT AVG(waitingTime) FROM trainingMeeting "
					 "INNER JOIN employee ON trainingMeeting.employeeID = employee.employeeID "
					 "WHERE employee.healthClubID = " + StringIntConverter::intToString(healthClubID);

		MYSQL_RES* result = db.queryResult(SQL);

		int rowCount = mysql_num_rows(result);

		if(rowCount > 0)
		{
			MYSQL_ROW row = mysql_fetch_row(result);
			return StringIntConverter::stringToInt(row[0]);
		}
		else
		{
			return 0;
		}
	}

} /* namespace Tom_F */
