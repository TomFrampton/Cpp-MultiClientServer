/*
 * SimulationData.cpp
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#include "SimulationData.h"

namespace Tom_F {

	SimulationData::SimulationData() :
	enrolledCount(0),
	averageWaitingTime(0)
	{
	}


	SimulationData::SimulationData(const SimulationData& toCopy) :
	enrolledCount(toCopy.getEnrolledCount()),
	averageWaitingTime(toCopy.getAverageWaitingTime())
	{
	}

	SimulationData::SimulationData(int enrolledCount, int averageWaitingTime) :
	enrolledCount(enrolledCount),
	averageWaitingTime(averageWaitingTime)
	{

	}

	SimulationData::~SimulationData()
	{
	}

	int SimulationData::getEnrolledCount() const
	{
		return enrolledCount;
	}

	int SimulationData::getAverageWaitingTime() const
	{
		return averageWaitingTime;
	}

} /* namespace Tom_F */
