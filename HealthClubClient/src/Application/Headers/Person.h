/*
 * @file 	 Person.h
 * @author	 Tom Frampton
 * @date 	 2013-02-18
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This is the base class for all humans in this simulation.
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
		Person(); // Default constructor
		Person(const Person& toCopy); // Copy constructor
		Person(string forename, string surname, char gender);
		virtual ~Person(); // Destructor

		void setForename(string forename);
		void setSurname(string surname);
		void setGender(char gen);

		string getForename() const;
		string getSurname() const;
		char getGender() const;

		// These would not be suitable as two different people could share the same name
		// I have implemented and commented out to show how I would do it though
		// bool operator==(const Person& toCompare) const;
		// bool operator!=(const Person& toCompare) const;

	    Person& operator=(const Person& toAssignFrom); // Overload assignment

		string toString() const;
		friend ostream& operator<<(ostream& os, const Person& person); // Overload <<

	private:
		string forename;
		string surname;
		char gender;

		// Allow direct access to data members for easier serialization
		friend class boost::serialization::access;

		/**
		 * Templated function to allow the use of input or ouput archives
		 * therefore allowing the same function to be used for serialization
		 * and deserialization
		 * @param   ar        The archive to use to (de)serialize this object
		 * @param   version   The version of boost::serialization to use
		 */
		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int version)
		{
			// The & symbol represents << or >> to allow serialization
			// and deserialzation using this same function
			ar & forename;
			ar & surname;
			ar & gender;
		}
	};

} /* namespace Tom_F */

#endif /* PERSON_H_ */
