/*
 * MemberMapper.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include <string>
#include <sstream>

#include <InvalidMemberException.h>

#include "StringIntConverter.h"
#include "MemberMapper.h"

using std::string;
using std::stringstream;

namespace Tom_F
{

	MemberMapper::MemberMapper()
	{
	}

	MemberMapper::~MemberMapper()
	{
	}

	/**
	 * Used to add a member to the database when they have been enrolled.
	 * @param   db             The database wrapper object to use
	 * @param   newMember      The non-member who is to be enrolled
	 * @param   healthClubID   The ID of the health club to register the member with
	 */
	int MemberMapper::addToDatabase(DBControlIF& db, const Guest& newMember, int healthClubID) const
	{
		// The MySQL query to add the member to the database
		string SQL = "INSERT INTO member (forename, surname, gender, healthClubID) VALUES"
				     "("
				        "'" + db.escapeString(newMember.getForename()) + "',"
				        "'" + db.escapeString(newMember.getSurname()) + "',"
				        "'" + newMember.getGender() + "',"
				         "" + StringIntConverter::intToString(healthClubID) + ""
				     ");";

		// Query the database asking for the insertID and return it
		return db.queryInsertID(SQL);
	}

	int MemberMapper::getMemberCount(DBControlIF& db, int healthClubID) const
	{
		string SQL = "SELECT COUNT(membershipID) FROM member "
				     "WHERE healthClubID = " + StringIntConverter::intToString(healthClubID);

		MYSQL_RES* result = db.queryResult(SQL);

		MYSQL_ROW row = mysql_fetch_row(result);
		return StringIntConverter::stringToInt(row[0]);
	}


	Member MemberMapper::getMemberByID(DBControlIF& db, int membershipID) const
	{
		string SQL = "SELECT * FROM member "
					 "WHERE membershipID = " + StringIntConverter::intToString(membershipID);

		MYSQL_RES* result = db.queryResult(SQL);

		int affectedRows = mysql_num_rows(result);

		if(affectedRows > 0)
		{
			MYSQL_ROW row = mysql_fetch_row(result);
			return fromRow(row);
		}
		else
		{
			throw Exception::InvalidMemberException();

		}
	}

	Member MemberMapper::fromRow(MYSQL_ROW row) const
	{
		Member newMember;
		newMember.setMembershipID(StringIntConverter::stringToInt(row[0]));
		newMember.setForename(row[1]);
		newMember.setSurname(row[2]);
		newMember.setGender(row[3][0]);
		return newMember;
	}

} /* namespace Tom_F */
