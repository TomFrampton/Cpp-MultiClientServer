/*
 * FileReader.cpp
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#include <fstream>
#include "FileReader.h"

using std::ifstream;

namespace Tom_F {

	FileReader::FileReader()
	{
	}

	FileReader::~FileReader()
	{
	}

	/**
	 * Reads lines of text from a file and puts each line into a vector slot.
	 * @param    textFile         The path of the file to read from
	 * @return   vector<string>   A collection containing the lines of text from file
	 */
	vector<string> FileReader::getLines(string textFile) const
	{
	   string line = ""; // The line hasn't been read yet
	   vector<string> lines; // Initialize the vector to be used
	   ifstream fileToRead(textFile.c_str()); // Create the file input stream from the file

	   // If file stream is open
	   if(fileToRead.is_open())
	   {
		   // Get each line in the text file
			while(getline(fileToRead,line))
			{
				lines.push_back(line); // Add line to the vector
			}
			fileToRead.close(); // Close the file stream
	   }
	   return lines; // Return the collection of lines
	}

} /* namespace Tom_F */
