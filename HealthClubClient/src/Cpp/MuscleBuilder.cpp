/*
 * MuscleBuilder.cpp
 *
 *  Created on: 4 Mar 2013
 *      Author: Tom
 */

#include "debug.h"

#include <windows.h>
#include <ctime>
#include <cstdlib>
#include "MuscleBuilder.h"

namespace Tom_F
{

	MuscleBuilder::MuscleBuilder()
	{
		// TODO Auto-generated constructor stub
	}

	MuscleBuilder::~MuscleBuilder()
	{
		// TODO Auto-generated destructor stub
	}

	void MuscleBuilder::exercise(Member& trainee)
	{
		cout << "good" << endl;
		srand(static_cast<unsigned>(time(0)));

		double weightLossPC = 1 - ((static_cast<double>(rand() % 3) - 1) / 10);
		trainee.setWeight(trainee.getWeight() * weightLossPC);
		cout << "good" << endl;
		Sleep(15000);
	}

} /* namespace Tom_F */
