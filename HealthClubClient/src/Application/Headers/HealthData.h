/*
 * HealthData.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef HEALTHDATA_H_
#define HEALTHDATA_H_

#include <string>
#include <boost/serialization/access.hpp>

#include "HealthCalculator.h"

#include "Member.h"

namespace Tom_F
{
	class HealthData
	{
	public:
		HealthData();
		HealthData(int memberID, int height, int weight);
		HealthData(Member& customer);
		virtual ~HealthData();

		int getMembershipID() const;
		int getHeight() const;
		int getWeight() const;

		string toProgressString(const HealthData& oldData) const;

	private:
		int membershipID;
		int height;
		int weight;

		friend class boost::serialization::access;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar & membershipID;
			ar & height;
			ar & weight;
		}

	};

} /* namespace Tom_F */
#endif /* HEALTHDATA_H_ */
