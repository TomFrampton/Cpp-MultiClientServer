/*
 * HealthDataMapper.h
 *
 *  Created on: 27 Feb 2013
 *      Author: Tom
 */

#ifndef HEALTHDATAMAPPER_H_
#define HEALTHDATAMAPPER_H_

#include <vector>

#include "DBControlIF.h"
#include "HealthData.h"

using std::vector;

namespace Tom_F
{
	class HealthDataMapper
	{
	public:
		HealthDataMapper();
		virtual ~HealthDataMapper();

		int addToDatabase(DBControlIF& db, const HealthData& stats);
		HealthData getLastHealthLog(DBControlIF& db, int memberID);
	};

} /* namespace Tom_F */

#endif /* HEALTHDATAMAPPER_H_ */
