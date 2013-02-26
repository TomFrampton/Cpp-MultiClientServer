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

namespace Tom_F {

	class HealthData
	{
	public:
		HealthData();
		HealthData(int height, int weight, double bodyFatPC);
		virtual ~HealthData();

		int getHeight() const;
		int getWeight() const;
		double getBodyFatPC() const;

	private:
		int height;
		int weight;
		double bodyFatPC;

		friend class boost::serialization::access;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar & height;
			ar & weight;
			ar & bodyFatPC;
		}

	};

} /* namespace Tom_F */
#endif /* HEALTHDATA_H_ */
