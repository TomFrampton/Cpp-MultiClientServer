/*
 * Person.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include "Person.h"

namespace Tom_F {

	Person::Person()
	{
		forename = "Default";
		surname = "Default";
	}

	Person::~Person()
	{
		// TODO Auto-generated destructor stub
	}

	void Person::setForename(string forename)
	{
		this->forename = forename;
	}

	void Person::setSurname(string surname)
	{
		this->surname = surname;
	}

	string Person::getForename() const
	{
		return forename;
	}

	string Person::getSurname() const
	{
		return surname;
	}

} /* namespace Tom_F */
