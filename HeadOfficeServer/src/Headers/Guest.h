/*
 * Guest.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef GUEST_H_
#define GUEST_H_

#include <iostream>
#include <string>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>

#include "Customer.h"

using std::ostream;
using std::istream;
using std::string;

namespace Tom_F
{

	class Guest : public Customer
	{
	public:
		Guest();
		Guest(string forename, string surname, int height, int weight, double bodyFatPC);
		virtual ~Guest();

		friend ostream& operator<<(ostream& os, const Guest& guest);

	private:

		friend class boost::serialization::access;

		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Customer>(*this);
		}
	};

} /* namespace Tom_F */
#endif /* GUEST_H_ */
