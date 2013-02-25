/*
 * ComplexGuestGenerator.cpp
 *
 *  Created on: 25 Feb 2013
 *      Author: Tom
 */

#include <cstdlib>
#include <ctime>

#include "ComplexGuestGenerator.h"

namespace Tom_F
{
	ComplexGuestGenerator::ComplexGuestGenerator()
	{
		// TODO Auto-generated constructor stub
	}


	ComplexGuestGenerator::~ComplexGuestGenerator()
	{
		// TODO Auto-generated destructor stub
	}

	Guest ComplexGuestGenerator::generateGuest() const
	{
		static string forenames[] = {"Tom", "Steve", "Ben", "Pete", "Chris", "Daniel"};
		static int forenamesCount = 6;

		static string surnames[] = {"Smith", "Jones", "Brown", "Wilson", "Simpson", "Green"};
		static int surnamesCount = 6;

		srand((unsigned)time(0));

		string forename = forenames[rand() % forenamesCount];
		string surname = surnames[rand() % surnamesCount];

		return Guest(forename, surname);

	}

} /* namespace Tom_F */
