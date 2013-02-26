/*
 * Customer.h
 *
 *  Created on: 26 Feb 2013
 *      Author: Tom
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Person.h"

#include <boost/serialization/base_object.hpp>

namespace Tom_F {

	class Customer : public Person
	{
	public:
		Customer();
		Customer(string forename, string surname, int height, int weight, double bodyFatPC);
		virtual ~Customer();

		int getHeight() const;
		int getWeight() const;
		double getBodyFatPC() const;

	private:
		int height;
		int weight;
		double bodyFatPC;

		friend class boost::serialization::access;

		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Person>(*this);
			ar & height;
			ar & weight;
			ar & bodyFatPC;
		}
	};

} /* namespace Tom_F */
#endif /* CUSTOMER_H_ */
