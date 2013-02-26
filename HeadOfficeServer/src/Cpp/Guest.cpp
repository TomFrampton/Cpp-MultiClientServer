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

	Guest::Guest() :
	Customer()
	{
	}

	Guest::Guest(string forename, string surname, int height, int weight, double bodyFatPC) :
	Customer(forename, surname, height, weight, bodyFatPC)
	{
	}

	Guest::~Guest() {
		// TODO Auto-generated destructor stub
	}

	ostream& operator<<(ostream& os, const Guest& guest)
	{
		os << guest.getForename() + " " + guest.getSurname() + " ";
		return os;
	}

} /* namespace Tom_F */
