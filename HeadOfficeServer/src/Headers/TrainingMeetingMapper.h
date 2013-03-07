/*
 * TrainingMeetingMapper.h
 *
 *  Created on: 28 Feb 2013
 *      Author: Tom
 */

#ifndef TRAININGMEETINGMAPPER_H_
#define TRAININGMEETINGMAPPER_H_

#include <TrainingMeeting.h>

namespace Tom_F
{

	class TrainingMeetingMapper
	{
	public:
		TrainingMeetingMapper();
		virtual ~TrainingMeetingMapper();

		bool addToDatabase(DBControl& db, const TrainingMeeting& meeting) const;
		int getAverageWaitingTime(DBControl& db, int healthClubID) const;
	};

} /* namespace Tom_F */

#endif /* TRAININGMEETINGMAPPER_H_ */
