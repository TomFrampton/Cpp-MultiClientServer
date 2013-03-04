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

namespace Tom_F {

	PersonGenerator::PersonGenerator()
	{
		FileReader reader;
		maleForenames = reader.getLines("male_forenames.txt");
		femaleForenames = reader.getLines("female_forenames.txt");
		surnames = reader.getLines("surnames.txt");

		if(maleForenames.size() == 0)
		{
			maleForenames.push_back("Default");
		}

		if(femaleForenames.size() == 0)
		{
			femaleForenames.push_back("Default");
		}

		if(surnames.size() == 0)
		{
			surnames.push_back("Default");
		}

		srand(static_cast<unsigned>(time(0)));
	}

	PersonGenerator::~PersonGenerator()
	{
	}

	Person PersonGenerator::generatePerson()
	{
		static char genders[] = {'M', 'F'};
		char gender = genders[rand() % 2];

		const vector<string>* forenames;

		if(gender == 'M')
		{
			forenames = &maleForenames;
		}
		else
		{
			forenames = &femaleForenames;
		}

		string forename = (*forenames)[rand() % forenames->size()];
		string surname = surnames[rand() % surnames.size()];

		return Person(forename, surname, gender);
	}


} /* namespace Tom_F */
