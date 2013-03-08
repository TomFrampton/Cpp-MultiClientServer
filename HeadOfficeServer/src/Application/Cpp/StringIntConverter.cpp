/*
 * StringIntConverter.cpp
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#include <sstream>
#include <cstdlib>

#include "StringIntConverter.h"

using std::stringstream;

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

	int StringIntConverter::stringToInt(string toConvert)
	{
		return atoi(toConvert.c_str());
	}

} /* namespace Tom_F */
