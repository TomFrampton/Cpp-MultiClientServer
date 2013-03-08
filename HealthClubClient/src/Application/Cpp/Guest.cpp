/*
 * Guest.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include <sstream>
#include <string>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "Guest.h"

using std::string;
using std::stringstream;

namespace Tom_F {

	Guest::Guest()
	{
	}

	Guest::Guest(const Guest& toCopy) :
	Customer(toCopy)
	{
	}

	Guest::Guest(const Person& toConvert, int height, int weight) :
	Customer(toConvert, height, weight)
	{
	}

	Guest::Guest(string forename, string surname, char gender, int height, int weight) :
	Customer(forename, surname, gender, height, weight)
	{
	}

	Guest::~Guest()
	{
	}

	ostream& operator<<(ostream& os, const Guest& guest)
	{
		os << guest.getForename() + " " + guest.getSurname() + " ";
		return os;
	}

} /* namespace Tom_F */
