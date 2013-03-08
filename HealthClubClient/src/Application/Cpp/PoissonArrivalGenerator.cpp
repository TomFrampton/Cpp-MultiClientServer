/*
 * PoissonArrivalGenerator.cpp
 *
 *  Created on: 24 Feb 2013
 *      Author: Tom
 */

#include <cmath>
#include <cstdlib>
#include <ctime>

#include "PoissonArrivalGenerator.h"

namespace Tom_F {

	/**
	 * Default constructor.
	 */
	PoissonArrivalGenerator::PoissonArrivalGenerator() :
	arrivalCount(0),
	nextArrivalSlot(0),
	arrivalSlots(NULL)
	{
	}

	/**
	 * Constructor. Set up the arrival generator using the values passed.
	 * @param   arrivalCount      The number of arrival slots
	 * @param   averageInterval   The average time between arrivals
	 */
	PoissonArrivalGenerator::PoissonArrivalGenerator(int arrivalCount, int averageInterval) :
	arrivalCount(arrivalCount),
	nextArrivalSlot(0)
	{
		arrivalSlots = (bool*)malloc(arrivalCount * sizeof(bool)); // Allocate space for the arrival slots
		generateArrivals(arrivalCount, averageInterval); // Generate the arrivals array
	}

	/**
	 * Destructor.
	 */
	PoissonArrivalGenerator::~PoissonArrivalGenerator()
	{
		free(arrivalSlots); // Deallocate the arrival slots array memory
	}

	/**
	 * Check if the next arrival slot generated indicates a successful arrival
	 * @return   bool   Indicate that someone has arrived or not
	 */
	bool PoissonArrivalGenerator::hasArrived()
	{
		// If reached end of the arrival slots array
		if(nextArrivalSlot >= arrivalCount)
		{
			return false;
		}
		else // Slots still to test
		{
			// Return the arrival result for the current slot and increment index
			return arrivalSlots[nextArrivalSlot++];
		}
	}

	/**
	 * Gets the number of arrival slots this generator has generated
	 * @return   int   The number of arrival slots
	 */
	int PoissonArrivalGenerator::getArrivalCount() const
	{
		return arrivalCount;
	}

	/**
	 * Generates the arrivals array filling it will booleans to indicate if there has been
	 * a successful arrival in that time slot
	 * @param   arrivalsToGen     The number of arrival slots to generate
	 * @param   averageInterval   The average interval between arrivals
	 */
	void PoissonArrivalGenerator::generateArrivals(int arrivalsToGen, int averageInterval)
	{
		// Probability of an arrival occuring
		double arrivalProbability = 1 / static_cast<double>(averageInterval);
		// Get the poisson value
		double poissonValue = std::exp(-arrivalProbability);

		int randomValue = 0;
		srand((unsigned)time(0)); // Seed the random generator

		// For each arrival slot
		for(int i = 0; i < arrivalsToGen; i++)
		{
			randomValue = rand() % averageInterval; // Get random value based on average arrival times
			// Compare to poisson value and save result in the current arrival slot
			arrivalSlots[i] = randomValue < poissonValue;
		}
	}

} /* namespace Tom_F */
