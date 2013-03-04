/*
 * HealthCalculator.h
 *
 *  Created on: 25 Feb 2013
 *      Author: Tom
 */

#ifndef HEALTHCALCULATOR_H_
#define HEALTHCALCULATOR_H_

#include <string>
#include "Member.h"
#include "HealthData.h"

using std::string;

namespace Tom_F
{
	class HealthCalculator {
	public:
		HealthCalculator();
		virtual ~HealthCalculator();

		string getHealthString(const HealthData& data, char gender) const;
		double getBMI(const HealthData& data) const;
		int getLeanMass(const HealthData& data, char gender) const;
		double getBodySurfaceArea(const HealthData& data) const;

	};

} /* namespace Tom_F */
#endif /* HEALTHCALCULATOR_H_ */
