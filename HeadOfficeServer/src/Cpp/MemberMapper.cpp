/*
 * MemberMapper.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include <string>
#include <sstream>

#include <InvalidMemberException.h>

#include "debug.h"

#include "MemberMapper.h"

using std::string;
using std::stringstream;

namespace Tom_F
{

	MemberMapper::MemberMapper() {
		// TODO Auto-generated constructor stub

	}

	MemberMapper::~MemberMapper() {
		// TODO Auto-generated destructor stub
	}

	int MemberMapper::addMemberToDatabase(const Guest& newMember) const
	{
		DBControl db;
		db.connect();

		string SQL = "INSERT INTO member (forename, surname) VALUES"
				     "("
				        "'" + db.escapeString(newMember.getForename()) + "',"
				        "'" + db.escapeString(newMember.getSurname()) + "'"
				     ");";

		db.query(SQL);

		int membershipID = mysql_insert_id(db.getConnection());
		db.close();
		return membershipID;
	}

	Member MemberMapper::getMemberByID(int membershipID) const
	{
		DBControl db;
		db.connect();

		stringstream id;
		id << membershipID;

		string SQL = "SELECT * FROM member "
					 "WHERE membershipID = " + id.str();

		MYSQL_RES* result = db.query(SQL);

		int affectedRows = mysql_num_rows(result);
		db.close();

		if(affectedRows > 0)
		{
			MYSQL_ROW row = mysql_fetch_row(result);
			//return fromRow(row);
		}
		else
		{
			throw exception::InvalidMemberException();

		}
	}

	Member MemberMapper::fromRow(MYSQL_ROW row) const
	{/*
		Member newMember(atoi(row[0]));
		newMember.setForename(row[1]);
		newMember.setSurname(row[2]);*/
	}

} /* namespace Tom_F */
