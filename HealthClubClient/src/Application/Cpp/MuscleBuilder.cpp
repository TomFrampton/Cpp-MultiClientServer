/*
 * MuscleBuilder.cpp
 *
 *  Created on: 4 Mar 2013
 *      Author: Tom
 */

#include <windows.h>
#include <ctime>
#include <cstdlib>
#include "MuscleBuilder.h"

namespace Tom_F
{

	MuscleBuilder::MuscleBuilder()
	{
	}

	MuscleBuilder::~MuscleBuilder()
	{
	}

	/**
	 * Simulates an exercise program for member who aren't looking to lose
	 * much weight. Uses a random algorithm to simulate weight loss
	 * @param   trainee   The member who is on the exercise program
	 */
	void MuscleBuilder::exercise(Member& trainee)
	{
		srand(static_cast<unsigned>(time(0))); // Seed random generator

		// Generate a random number between 0.99 and 0.80
		double weightLossPC = 1 - ((static_cast<double>(rand() % 20) + 1) / 100);
		// Times by the members weight to simulate weight loss
		trainee.setWeight(trainee.getWeight() * weightLossPC);

		// Takes 15 seconds to complete
		Sleep(15000);
	}

} /* namespace Tom_F */
