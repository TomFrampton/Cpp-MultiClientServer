/*
 * PoissonArrivalGenerator.cpp
 *
 *  Created on: 24 Feb 2013
 *      Author: Tom
 */
#include "debug.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

#include "PoissonArrivalGenerator.h"

namespace Tom_F {

	PoissonArrivalGenerator::PoissonArrivalGenerator() :
	arrivalSlotsSize(0),
	nextArrivalSlot(0)
	{
		arrivalSlots = new bool[0];
	}

	PoissonArrivalGenerator::PoissonArrivalGenerator(int arrivalSlotsSize, int averageInterval) :
	arrivalSlotsSize(arrivalSlotsSize),
	nextArrivalSlot(0)
	{
		this->arrivalSlots = new bool[arrivalSlotsSize];
		generateArrivals(arrivalSlotsSize, averageInterval);
	}

	PoissonArrivalGenerator::~PoissonArrivalGenerator() {
		delete[] arrivalSlots;
	}

	bool PoissonArrivalGenerator::hasArrived()
	{
		if(nextArrivalSlot >= arrivalSlotsSize)
		{
			return false;
		}
		else
		{
			return arrivalSlots[nextArrivalSlot++];
		}
	}

	int PoissonArrivalGenerator::getArrivalSlotsSize() const
	{
		return arrivalSlotsSize;
	}

	void PoissonArrivalGenerator::generateArrivals(int arrivalSlotsSize, int averageInterval)
	{

		double arrivalProbability = 1 / static_cast<double>(averageInterval);
		double poissonValue = std::exp(-arrivalProbability);

		int randomValue = 0;
		srand((unsigned)time(0));

		for(int i = 0; i < arrivalSlotsSize; i++)
		{
			randomValue = rand() % averageInterval;
			arrivalSlots[i] = randomValue < poissonValue;
		}
	}

} /* namespace Tom_F */
