/*
 * HealthData.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include "HealthData.h"

namespace Tom_F
{
	HealthData::HealthData() :
	height(0),
	weight(0),
	bodyFatPC(0)
	{
		// TODO Auto-generated constructor stub
	}

	HealthData::HealthData(int height, int weight, double bodyFatPC) :
	height(height),
	weight(weight),
	bodyFatPC(bodyFatPC)
	{
		// TODO Auto-generated constructor stub
	}

	HealthData::~HealthData()
	{
		// TODO Auto-generated destructor stub
	}

	int HealthData::getHeight() const
	{
		return height;
	}

	int HealthData::getWeight() const
	{
		return weight;
	}

	double HealthData::getBodyFatPC() const
	{
		return bodyFatPC;
	}

} /* namespace Tom_F */
