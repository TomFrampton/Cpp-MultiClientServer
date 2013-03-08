/*
 * HealthDataMapper.cpp
 *
 *  Created on: 27 Feb 2013
 *      Author: Tom
 */

#include <sstream>

#include "InvalidMemberException.h"

#include "StringIntConverter.h"
#include "HealthDataMapper.h"

using std::stringstream;

namespace Tom_F
{
	HealthDataMapper::HealthDataMapper()
	{
	}

	HealthDataMapper::~HealthDataMapper()
	{
	}

	int HealthDataMapper::addToDatabase(DBControlIF& db, const HealthData& data)
	{
		stringstream membershipID;
		stringstream height;
		stringstream weight;

		membershipID << data.getMembershipID();
		height << data.getHeight();
		weight << data.getWeight();

		string SQL = "INSERT INTO healthData (membershipID, timeRecorded, height,"
				                             "weight) VALUES"
			         "("
			            "" + membershipID.str() + ","
			               " CURRENT_TIMESTAMP(),"
			            "" + height.str() + ","
			            "" + weight.str() + ""
			     ");";

		return db.queryAffectedRows(SQL);
	}


	HealthData HealthDataMapper::getLastHealthLog(DBControlIF& db, int memberID)
	{
		string SQL = "SELECT * FROM healthData "
					 "WHERE membershipID = " + StringIntConverter::intToString(memberID) + " "
					 "ORDER BY timeRecorded DESC "
					 "LIMIT 1";

		MYSQL_RES* result = db.queryResult(SQL);

		int rowCount = mysql_num_rows(result);

		if(rowCount > 0)
		{
			MYSQL_ROW row = mysql_fetch_row(result);
			int membershipID = StringIntConverter::stringToInt(row[0]);
			int height = StringIntConverter::stringToInt(row[2]);
			int weight = StringIntConverter::stringToInt(row[3]);
			return HealthData(membershipID, height, weight);
		}
		else
		{
			throw Exception::InvalidMemberException(memberID, "No existing health data for this member");
		}
	}

} /* namespace Tom_F */
