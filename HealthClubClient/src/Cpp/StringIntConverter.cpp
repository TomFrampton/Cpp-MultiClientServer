/*
 * StringIntConverter.cpp
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "StringIntConverter.h"

using std::stringstream;
using std::ios;
using std::setprecision;

namespace Tom_F
{
	StringIntConverter::StringIntConverter()
	{
	}

	StringIntConverter::~StringIntConverter()
	{
	}

	string StringIntConverter::intToString(int toConvert)
	{
		stringstream ss;
		ss << toConvert;
		return ss.str();
	}

	string StringIntConverter::doubleToString(double toConvert, int decPlaces)
	{
		stringstream ss;
		ss.setf(ios::fixed);
		ss << setprecision(2) << toConvert;
		return ss.str();
	}

	int StringIntConverter::stringToInt(string toConvert)
	{
		return atoi(toConvert.c_str());
	}

} /* namespace Tom_F */
