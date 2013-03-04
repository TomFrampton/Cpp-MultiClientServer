/*
 * FileReader.h
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <vector>
#include <string>

using std::string;
using std::vector;

namespace Tom_F {

class FileReader
{
	public:
		FileReader();
		virtual ~FileReader();

		vector<string> getLines(string textFile) const;
	};

} /* namespace Tom_F */
#endif /* FILEREADER_H_ */
