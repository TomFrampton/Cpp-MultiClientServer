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

using std::ostream;
using std::istream;
using std::string;

namespace Tom_F {

	class Guest
	{
	public:
		Guest();
		Guest(string serializedString);
		virtual ~Guest();

		string getSerializedString() const;

		friend ostream& operator<<(ostream& os, const Guest& guest);

		string forename;
		string surname;

	private:

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar & forename;
			ar & surname;
		}


	};

} /* namespace Tom_F */
#endif /* GUEST_H_ */
