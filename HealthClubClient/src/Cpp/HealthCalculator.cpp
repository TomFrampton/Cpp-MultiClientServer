/*
 * HealthCalculator.cpp
 *
 *  Created on: 25 Feb 2013
 *      Author: Tom
 */

#include <cmath>
#include "HealthCalculator.h"
#include "StringIntConverter.h"

namespace Tom_F
{
	HealthCalculator::HealthCalculator()
	{
		// TODO Auto-generated constructor stub
	}

	HealthCalculator::~HealthCalculator()
	{
		// TODO Auto-generated destructor stub
	}

	string HealthCalculator::getHealthString(const HealthData& data, char gender) const
	{
		StringIntConverter converter;
		return "BMI: " + converter.doubleToString(getBMI(data), 2) + ", "
			   "LBM: " + converter.intToString(getLeanMass(data, gender)) + "kg, "
			   "BSA: " + converter.doubleToString(getBodySurfaceArea(data), 2) + "m/sq";
	}

	double HealthCalculator::getBMI(const HealthData& data) const
	{
		double height = static_cast<double>(data.getHeight());
		return data.getWeight() / ((height / 100) * (height / 100));
	}

	int HealthCalculator::getLeanMass(const HealthData& data, char gender) const
	{
		int weight = data.getWeight();

		if(gender == 'F')
		{
			return (1.07 * weight) - (148 * (pow(weight, 2) / (pow(data.getHeight(), 2))));
		}
		else
		{
			return (1.10 * weight) - (128 * (pow(weight, 2) / (pow(data.getHeight(), 2))));
		}
	}

	double HealthCalculator::getBodySurfaceArea(const HealthData& data) const
	{
		return sqrt(data.getHeight() * static_cast<double>(data.getWeight()) / 3600);
	}

} /* namespace Tom_F */
