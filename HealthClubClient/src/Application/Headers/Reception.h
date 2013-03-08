/*
 * Reception.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef RECEPTION_H_
#define RECEPTION_H_

#include <pthread.h>
#include <deque>
#include <boost/smart_ptr/shared_ptr.hpp>

#include "Guest.h"
#include "TrainerQueue.h"
#include "TrainingControl.h"
#include "HealthClubAdmin.h"

using std::vector;
using boost::shared_ptr;

namespace Tom_F
{

	class Reception
	{
	public:
		Reception();
		Reception(HealthClubAdmin* admin, TrainerQueue* trainers);
		virtual ~Reception();

		void arrive(Guest& arrival);
		SimulationData close();


	private:
		HealthClubAdmin* const admin;
		TrainerQueue* const trainers;

		deque<shared_ptr<Member> > members;
		vector<shared_ptr<TrainingControl> > trainingThreads;
	};

} /* namespace Tom_F */

#endif /* RECEPTION_H_ */
