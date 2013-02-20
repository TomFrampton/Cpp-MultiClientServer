/*
 * MemberMapper.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include <string>
#include "MemberMapper.h"

using std::string;

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
				        "'" + db.escapeString(newMember.forename) + "',"
				        "'" + db.escapeString(newMember.surname) + "'"
				     ");";

		db.query(SQL);

		return mysql_insert_id(db.getConnection());
	}

} /* namespace Tom_F */
