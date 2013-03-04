/*
 * FileReader.cpp
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#include "debug.h"
#include <fstream>
#include "FileReader.h"

using std::ifstream;

namespace Tom_F {

	FileReader::FileReader()
	{
		// TODO Auto-generated constructor stub
	}

	FileReader::~FileReader()
	{
		// TODO Auto-generated destructor stub
	}

	vector<string> FileReader::getLines(string textFile) const
	{
	   string line;
	   vector<string> lines;
	   ifstream fileToRead(textFile.c_str());

	   if(fileToRead.is_open())
	   {
			while(getline(fileToRead,line))
			{
				lines.push_back(line);
			}
			fileToRead.close();
	   }
	   return lines;
	}

} /* namespace Tom_F */
