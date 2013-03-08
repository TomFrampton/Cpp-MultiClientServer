/*
 * HealthData.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include "StringIntConverter.h"
#include "HealthData.h"

namespace Tom_F
{
	HealthData::HealthData() :
	membershipID(0),
	height(0),
	weight(0)
	{
	}

	HealthData::HealthData(int memberID, int height, int weight) :
	membershipID(memberID),
	height(height),
	weight(weight)
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

	string HealthData::toProgressString(const HealthData& oldData) const
	{
		HealthCalculator healthCalc;
		int weightLost = oldData.getWeight() - this->weight;
		double oldBMI = healthCalc.getBMI(oldData);
		double newBMI = healthCalc.getBMI(*this);
		double bmiLost = oldBMI - newBMI;

		string weightIndicator = "";
		if(weightLost >= 0)
		{
			weightIndicator = "Lost";
		}
		else
		{
			weightIndicator = "Gained";
			weightLost = 0 - weightLost;
		}

		string bmiIndicator = "";
		if(bmiLost >= 0)
		{
			bmiIndicator = "reduced";
		}
		else
		{
			bmiIndicator = "increased";
		}

		return weightIndicator + " " + StringIntConverter::intToString(weightLost) + "kgs and "
			   "" + bmiIndicator + " BMI from " + StringIntConverter::doubleToString(oldBMI,1) + " to "
			   "" + StringIntConverter::doubleToString(newBMI,1);
	}

} /* namespace Tom_F */
