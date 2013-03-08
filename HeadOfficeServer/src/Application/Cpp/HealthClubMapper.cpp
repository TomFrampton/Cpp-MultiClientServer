/*
 * HealthClubMapper.cpp
 *
 *  Created on: 27 Feb 2013
 *      Author: Tom
 */

#include <cstring>

#include "DBControlIF.h"
#include "HealthClubMapper.h"

using std::string;

namespace Tom_F
{
	HealthClubMapper::HealthClubMapper()
	{
	}

	HealthClubMapper::~HealthClubMapper()
	{
	}

	int HealthClubMapper::addToDatabase(DBControlIF& db) const
	{
		string SQL = "INSERT INTO healthClub VALUES ();";
		return db.queryInsertID(SQL);
	}

} /* namespace Tom_F */
