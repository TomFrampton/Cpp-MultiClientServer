/*
 * StringIntConverter.h
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#ifndef STRINGINTCONVERTER_H_
#define STRINGINTCONVERTER_H_

#include <string>

using std::string;

namespace Tom_F
{
	class StringIntConverter
	{
	public:
		StringIntConverter();
		virtual ~StringIntConverter();

		static string intToString(int toConvert);
		static string doubleToString(double toConvert, int decPlaces);
		static int stringToInt(string toConvert);
	};

} /* namespace Tom_F */
#endif /* STRINGINTCONVERTER_H_ */
