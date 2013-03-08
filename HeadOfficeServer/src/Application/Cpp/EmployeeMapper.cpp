/*
 * EmployeeMapper.cpp
 *
 *  Created on: 28 Feb 2013
 *      Author: Tom
 */

#include <sstream>
#include "DBControl.h"
#include "EmployeeMapper.h"

using std::stringstream;

namespace Tom_F
{
	EmployeeMapper::EmployeeMapper()
	{
	}

	EmployeeMapper::~EmployeeMapper()
	{
	}

	int EmployeeMapper::addToDatabase(DBControlIF& db, const Person& toHire,
											  string position, int healthClubID) const
	{
		stringstream clubIDString;
		clubIDString << healthClubID;

		string SQL = "INSERT INTO employee (forename, surname, position, healthClubID) VALUES"
				     "("
				        "'" + db.escapeString(toHire.getForename()) + "',"
				        "'" + db.escapeString(toHire.getSurname()) + "',"
				        "'" + position + "',"
				         "" + clubIDString.str() + ""
				     ");";

		return db.queryInsertID(SQL);
	}

} /* namespace Tom_F */
