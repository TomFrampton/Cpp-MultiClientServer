/*
 * PersonGenerator.cpp
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#include <ctime>
#include <cstdlib>

#include "FileReader.h"
#include "PersonGenerator.h"

namespace Tom_F
{
	/**
	 * Default constructor. Sets up the name vectors with suitable names to
	 * choose from. The names to be picked from are obtained by using a
	 * FileReader object to read lines from text files.
	 */
	PersonGenerator::PersonGenerator()
	{
		FileReader reader; // The FileReader to use
		// Get male names from the respective file
		maleForenames = reader.getLines("male_forenames.txt");
		// Same for female names
		femaleForenames = reader.getLines("female_forenames.txt");
		// And surnames
		surnames = reader.getLines("surnames.txt");

		if(maleForenames.size() == 0) // If no male names found
		{
			maleForenames.push_back("Default"); // Add a default name
		}

		if(femaleForenames.size() == 0) // If no female names found
		{
			femaleForenames.push_back("Default"); // Add default name
		}

		if(surnames.size() == 0) // If no surnames found
		{
			surnames.push_back("Default"); // Add default name
		}
		// Seed the random generator with current timestamp
		srand(static_cast<unsigned>(time(0)));
	}

	/**
	 * Destructor
	 */
	PersonGenerator::~PersonGenerator()
	{
	}

	/**
	 * Generates a random person by picking random names from the
	 * name vector data members
	 * @return   Person   The Person object that has been generated
	 */
	Person PersonGenerator::generatePerson()
	{
		static char genders[] = {'M', 'F'}; // Genders to pick from
		char gender = genders[rand() % 2]; // Pick a random gender

		const vector<string>* forenames; // Pointer to the forename object to use

		if(gender == 'M') // If gender was 'M'
		{
			forenames = &maleForenames; // Use male forenames
		}
		else // Gender was 'F'
		{
			forenames = &femaleForenames; // Use female names
		}

		// Get a random forename from the selected forename vector
		string forename = (*forenames)[rand() % forenames->size()];
		// Get a random surname
		string surname = surnames[rand() % surnames.size()];

		 // Create the Person object using the names selected
		return Person(forename, surname, gender);
	}


} /* namespace Tom_F */
