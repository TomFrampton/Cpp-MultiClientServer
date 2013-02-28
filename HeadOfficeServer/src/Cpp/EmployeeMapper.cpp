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
		// TODO Auto-generated constructor stub

	}

	EmployeeMapper::~EmployeeMapper()
	{
		// TODO Auto-generated destructor stub
	}

	int EmployeeMapper::addEmployeeToDatabase(const Person& toHire, string position, int healthClubID) const
	{
		stringstream clubIDString;
		clubIDString << healthClubID;

		DBControl db;
		db.connect();

		string SQL = "INSERT INTO employee (forename, surname, position, healthClubID) VALUES"
				     "("
				        "'" + db.escapeString(toHire.getForename()) + "',"
				        "'" + db.escapeString(toHire.getSurname()) + "',"
				        "'" + position + "',"
				         "" + clubIDString.str() + ""
				     ");";

		db.query(SQL);

		int employeeID = mysql_insert_id(db.getConnection());
		db.close();
		return employeeID;
	}

	} /* namespace Tom_F */
