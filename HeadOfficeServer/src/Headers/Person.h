/*
 * Person.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <boost/serialization/access.hpp>

using std::ostream;
using std::string;

namespace Tom_F
{
	class Person
	{
	public:
		Person();
		Person(string forename, string surname);
		virtual ~Person();

		void setForename(string forename);
		void setSurname(string surname);

		string getForename() const;
		string getSurname() const;

		friend ostream& operator<<(ostream& os, const Person& person);

	private:
		string forename;
		string surname;

		friend class boost::serialization::access;

		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int version)
		{
			ar & forename;
			ar & surname;
		}
	};

} /* namespace Tom_F */

#endif /* PERSON_H_ */
