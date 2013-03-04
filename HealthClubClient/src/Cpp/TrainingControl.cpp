/*
 * TrainingControl.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom Frampton
 *
 */

#include "debug.h"
#include "TrainerQueue.h"
#include "HealthData.h"
#include "HealthCalculator.h"
#include "IntenseWeightLoss.h"
#include "MuscleBuilder.h"

#include "TrainingControl.h"

namespace Tom_F
{

	TrainingControl::TrainingControl(Member* trainee, TrainerQueue* trainers, HealthClubAdmin* admin) :
	trainee(trainee),
	trainers(trainers),
	admin(admin),
	healthCalc(HealthCalculator())
	{
	}

	TrainingControl::~TrainingControl() {
		// TODO Auto-generated destructor stub
	}

	void TrainingControl::threadStart()
	{
		preMeeting();
	}

	void TrainingControl::preMeeting()
	{
		int startedWaiting = time(0);
		Trainer trainer = trainers->getTrainer();
		int waitingTime = time(0) - startedWaiting;

		HealthData data(*trainee);
		HealthCalculator healthCalc;

		admin->logHealthData(*trainee, data);
		Sleep(2000);

		ExerciseProgram* program;

		if(healthCalc.getBMI(data) > 30)
		{
			program = new IntenseWeightLoss;
		}
		else
		{
			program = new MuscleBuilder;
		}

		TrainingMeeting meeting(trainee->getMembershipID(), trainer.getEmployeeID(), waitingTime, "PRE");
		admin->logTrainingMeeting(meeting);

		trainers->returnTrainer(trainer);

		training(*program);
		delete program;
	}

	void TrainingControl::training(ExerciseProgram& program)
	{
		program.exercise(*trainee);
		postMeeting();
	}

	void TrainingControl::postMeeting()
	{
		int startedWaiting = time(0);
		Trainer trainer = trainers->getTrainer();
		int waitingTime = time(0) - startedWaiting;

		HealthData data(*trainee);

		admin->logHealthData(*trainee, data);
		Sleep(2000);
		TrainingMeeting meeting(trainee->getMembershipID(), trainer.getEmployeeID(), waitingTime, "POST");
		admin->logTrainingMeeting(meeting);

		trainers->returnTrainer(trainer);
	}

} /* namespace Tom_F */
