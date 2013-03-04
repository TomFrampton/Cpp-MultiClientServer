/*
 * IntenseWeightLoss.cpp
 *
 *  Created on: 4 Mar 2013
 *      Author: Tom
 */

#include "debug.h"

#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "IntenseWeightLoss.h"

namespace Tom_F
{
	IntenseWeightLoss::IntenseWeightLoss()
	{
		// TODO Auto-generated constructor stub
	}

	IntenseWeightLoss::~IntenseWeightLoss()
	{
		// TODO Auto-generated destructor stub
	}

	void IntenseWeightLoss::exercise(Member& trainee)
	{		cout << "good" << endl;
		srand(static_cast<unsigned>(time(0)));

		double weightLossPC = 1 - ((static_cast<double>(rand() % 5)) / 10);
		trainee.setWeight(trainee.getWeight() * weightLossPC);

		Sleep(20000);
	}

} /* namespace Tom_F */
