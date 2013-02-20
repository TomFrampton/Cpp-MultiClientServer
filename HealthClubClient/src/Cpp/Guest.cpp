/*
 * Guest.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include <sstream>
#include <string.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "Guest.h"

using std::string;
using std::stringstream;

namespace Tom_F {

	Guest::Guest() {
		forename = "Tom";
		surname = "Frampton";

	}

	Guest::Guest(string serializedString)
	{
		stringstream ss;
		ss << serializedString;

		boost::archive::text_iarchive ia(ss);
		ia >> *this;
	}

	Guest::~Guest() {
		// TODO Auto-generated destructor stub
	}

	string Guest::getSerializedString() const
	{
		stringstream ss;
		boost::archive::text_oarchive oa(ss);
		oa << *this;
		return ss.str();
	}

	/*template<class Archive>
	void Guest::serialize(Archive& ar, const unsigned int version)
	{
		ar & forename;
		ar & surname;
	}*/

	ostream& operator<<(ostream& os, const Guest& guest)
	{
		stringstream ss;
		ss << guest.forename << ',' << guest.surname;
		os << ss;
		return os;
	}



} /* namespace Tom_F */
