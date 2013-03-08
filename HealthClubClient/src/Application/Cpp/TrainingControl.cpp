/*
 * TrainingControl.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom Frampton
 *
 */

#include "TrainerQueue.h"
#include "HealthData.h"
#include "HealthCalculator.h"
#include "IntenseWeightLoss.h"
#include "MuscleBuilder.h"

#include "TrainingControl.h"

namespace Tom_F
{

	TrainingControl::TrainingControl(shared_ptr<Member> trainee, TrainerQueue* trainers, HealthClubAdmin* admin) :
	trainee(trainee),
	trainers(trainers),
	admin(admin),
	healthCalc(HealthCalculator())
	{
	}

	TrainingControl::~TrainingControl()
	{
	}

	/**
	 * The start of a new training thread.
	 */
	void TrainingControl::threadStart()
	{
		preMeeting(); // First thing to do is a pre meeting
	}

	/**
	 * This method controls the flow through a pre training meeting.
	 */
	void TrainingControl::preMeeting()
	{
		int startedWaiting = time(0); // Time started waiting for a trainer
		/* Get a trainer from the queue. The getTrainer() method encapsulates
		 * the use of semaphores to sleep and be woken up when a trainer
		 * becomes available
		 */
		Trainer trainer = trainers->getTrainer();
		int waitingTime = time(0) - startedWaiting; // How long did I wait for?

		HealthData data(*trainee); // Get the members health data
		HealthCalculator healthCalc; // Used to calculate BMI etc

		// Log the training meeting on the server
		TrainingMeeting meeting(trainee->getMembershipID(), trainer.getEmployeeID(), waitingTime, "PRE");
		admin->logTrainingMeeting(meeting, *trainee);

		// Call the admin object to log the members health data on the server
		admin->logHealthData(*trainee, data, false);
		Sleep(5000); // This meeting will take 5 minutes

		ExerciseProgram* program; // Will hold the training program once selected

		// Find out which exercise program the user requires
		if(healthCalc.getBMI(data) > 30) // If BMI higher than 30
		{
			program = new IntenseWeightLoss; // Need to lose weight
		}
		else
		{
			program = new MuscleBuilder; // Otherwise need some muscle
		}

		// Trainer is finished. Return him to his queue.
		trainers->returnTrainer(trainer);

		training(*program); // Start the training program
		delete program; // Training program finished - delete it
	}

	/**
	 * This method runs the selected exercise program for this member
	 * @param   program   The selected exercise program
	 */
	void TrainingControl::training(ExerciseProgram& program)
	{
		program.exercise(*trainee); // Use this exercise algorithm on the member
		postMeeting(); // Send them for their post training meeting
	}

	void TrainingControl::postMeeting()
	{
		int startedWaiting = time(0);
		Trainer trainer = trainers->getTrainer();
		int waitingTime = time(0) - startedWaiting;

		HealthData data(*trainee);

		admin->logHealthData(*trainee, data, true);
		Sleep(5000);
		TrainingMeeting meeting(trainee->getMembershipID(), trainer.getEmployeeID(), waitingTime, "POST");
		admin->logTrainingMeeting(meeting, *trainee);

		trainers->returnTrainer(trainer);
	}

} /* namespace Tom_F */
