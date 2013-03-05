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
	membershipID(0),
	height(0),
	weight(0)
	{
	}

	HealthData::HealthData(Member& trainee) :
	membershipID(trainee.getMembershipID()),
	height(trainee.getHeight()),
	weight(trainee.getWeight())
	{
	}

	HealthData::~HealthData()
	{
	}

	int HealthData::getMembershipID() const
	{
		return membershipID;
	}

	int HealthData::getHeight() const
	{
		return height;
	}

	int HealthData::getWeight() const
	{
		return weight;
	}

} /* namespace Tom_F */
