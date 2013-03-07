/*
 * GuestGenerator.cpp
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#include <ctime>
#include <cstdlib>

#include "Person.h"
#include "PersonGenerator.h"
#include "GuestGenerator.h"

namespace Tom_F
{
	/**
	 * Constructor. Sets the person generator to use and seeds the random generator
	 * @param  personGen  The generator to use to generate the Person base class
	 */
	GuestGenerator::GuestGenerator(PersonGenerator& personGen) :
	personGen(personGen)
	{
		srand(static_cast<unsigned>(time(0)));
	}

	/**
	 * Destructor
	 */
	GuestGenerator::~GuestGenerator()
	{
	}

	/**
	 * Generates the Person base object and the Guest object
	 * @return   Guest   The randomly generated Guest object
	 */
	Guest GuestGenerator::generateGuest()
	{
		// Use the person generator to make a person
		Person person = personGen.generatePerson();
		int height = (rand() % 40) + 160; // Generate random height
		int weight = (rand() % 40) + 80; // Generate random weight
		// Create a guest using the random person object, height and weight
		return Guest(person, height, weight);
	}

} /* namespace Tom_F */
