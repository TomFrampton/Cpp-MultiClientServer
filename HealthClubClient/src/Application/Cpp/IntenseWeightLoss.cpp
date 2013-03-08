/*
 * IntenseWeightLoss.cpp
 *
 *  Created on: 4 Mar 2013
 *      Author: Tom
 */


#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "IntenseWeightLoss.h"

namespace Tom_F
{
	IntenseWeightLoss::IntenseWeightLoss()
	{
	}

	IntenseWeightLoss::~IntenseWeightLoss()
	{
	}

	/**
	 * Simulates a training program of a member who is looking to lose
	 * a lot of weight. Uses a random algorithm to simulate weight loss.
	 * @param   trainee   The member who is training
	 */
	void IntenseWeightLoss::exercise(Member& trainee)
	{
		srand(static_cast<unsigned>(time(0))); // Seed random generator

		// Get a random number between 0.99 and 0.40
		double weightLossPC = 1 - ((static_cast<double>(rand() % 40) + 1) / 100);
		// Times that number by the person's weight to simulate weight loss
		trainee.setWeight(trainee.getWeight() * weightLossPC);

		// This training program will take 20 seconds
		Sleep(20000);
	}


} /* namespace Tom_F */
