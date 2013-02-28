/*
 * HealthClubMapper.cpp
 *
 *  Created on: 27 Feb 2013
 *      Author: Tom
 */

#include <cstring>
#include <DBControl.h>

#include "HealthClubMapper.h"

using std::string;

namespace Tom_F {

	HealthClubMapper::HealthClubMapper()
	{
		// TODO Auto-generated constructor stub
	}

	HealthClubMapper::~HealthClubMapper()
	{
		// TODO Auto-generated destructor stub
	}

	int HealthClubMapper::addHealthClubToDatabase() const
	{
		DBControl db;
		db.connect();

		string SQL = "INSERT INTO healthClub VALUES ();";

		db.query(SQL);

		int healthClubID = mysql_insert_id(db.getConnection());

		db.close();

		return healthClubID;
	}

} /* namespace Tom_F */
