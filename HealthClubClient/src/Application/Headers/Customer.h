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
		Customer(const Customer& toCopy);
		Customer(const Person& toConvert, int height, int weight);
		Customer(string forename, string surname, char gender, int height, int weight);
		virtual ~Customer();

		void setHeight(int height);
		void setWeight(int weight);

		int getHeight() const;
		int getWeight() const;

	private:
		int height;
		int weight;

		 /* Allow boost::serialization::access to directly access private members for
		  * serialize function below.
		  */
		friend class boost::serialization::access;

		/**
		 * Implements boost serialization to provide a function for (de)serializing
		 * this object. This function can be used to both serialize and deserialize
		 * the object because 1. 'Archive' is a template type so both in/out archives
		 * can be used and 2. & represents << or >> depending on the type of archive
		 * used.
		 * @param   ar        The archive to use to save/load the object to/from
		 * @param   version   The version of boost::serialization to use
		 */
		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int version)
		{
			// Serialize the base object person
			ar & boost::serialization::base_object<Person>(*this);
			ar & height; // Serialize height
			ar & weight; // Serialize weight
		}
	};

} /* namespace Tom_F */
#endif /* CUSTOMER_H_ */
