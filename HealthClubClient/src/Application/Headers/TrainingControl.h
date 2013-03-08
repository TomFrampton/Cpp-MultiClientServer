/*
 * TrainingControl.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom Frampton
 */

#ifndef TRAININGCONTROL_H_
#define TRAININGCONTROL_H_

#include <boost/smart_ptr/shared_ptr.hpp>

#include "Thread.h"
#include "Member.h"
#include "HealthClubAdmin.h"
#include "HealthCalculator.h"
#include "ExerciseProgram.h"
#include "TrainerQueue.h"

using boost::shared_ptr;

namespace Tom_F
{

	class TrainingControl : public Thread
	{
	public:
		TrainingControl(shared_ptr<Member> trainee, TrainerQueue* trainers, HealthClubAdmin* admin);
		virtual ~TrainingControl();

	protected:
		void threadStart();

	private:
		shared_ptr<Member> trainee;
		TrainerQueue* trainers;
		HealthClubAdmin* admin;

		HealthCalculator healthCalc;

		void preMeeting();
		void training(ExerciseProgram& program);
		void postMeeting();
	};

} /* namespace Tom_F */

#endif /* TRAININGCONTROL_H_ */
