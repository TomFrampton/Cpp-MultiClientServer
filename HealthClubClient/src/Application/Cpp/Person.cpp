/*
 * @file 	 Person.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-18
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This is the base class for all humans in this simulation.
 */

#include <sstream>

#include "Person.h"

using std::stringstream;

namespace Tom_F {

	/**
	 * Default constructor
	 */
	Person::Person() :
	forename("Default"),
	surname("Default"),
	gender('M')
	{
	}

	/**
	 * Copy constructor
	 * @param   toCopy   The Person object to make a copy of
	 */
	Person::Person(const Person& toCopy) :
	forename(toCopy.getForename()),
	surname(toCopy.getSurname()),
	gender(toCopy.getGender())
	{
	}

	/**
	 * Construct the person specifying their names and gender
	 * @param   forename   The person's forename
	 * @param   surname    The person's surname
	 * @param   gender     The person's gender ('M' or 'F')
	 */
	Person::Person(string forename, string surname, char gender) :
	forename(forename),
	surname(surname)
	{
		setGender(gender); // Gender must be validated first
	}

	/**
	 * Destructor
	 */
	Person::~Person()
	{
	}

	/**
	 * Set the person's forename
	 * @param   forename   The person's new forename
	 */
	void Person::setForename(string forename)
	{
		this->forename = forename;
	}

	/**
	 * Set the person's surname
	 * @param   surname   The person's new surname
	 */
	void Person::setSurname(string surname)
	{
		this->surname = surname;
	}

	/**
	 * Set the person's gender
	 * @param   gen   The person's new gender
	 */
	void Person::setGender(char gen)
	{
		// Check that the input is a valid gender
		if(gen == 'M' || gen == 'F' || gen == 'm' || gen == 'f')
		{
			// Input valid. Change to upper case and assign to gender
			gender = toupper(gen);
		}
		else
		{
			// Input is not valid. Set gender to 'M' as default
			gender = 'M';
		}
	}

	/**
	 * Get the person's forename
	 * @return   string   The person's forename
	 */
	string Person::getForename() const
	{
		return forename;
	}

	/**
	 * Get the person's surname
	 * @return   string   The person's surname
	 */
	string Person::getSurname() const
	{
		return surname;
	}

	/**
	 * Get the person's gender
	 * @return   char   The person's gender ('M' or 'F')
	 */
	char Person::getGender() const
	{
		return gender;
	}

	/**
	 * Overload the equality operator
	 * @param   toCompare   The Person to compare with 'this' Person
	 * @return  bool        Are the Persons' data members identical

	bool Person::operator==(const Person& toCompare) const
	{
		return (forename == toCompare.getForename()) &&
			   (surname == toCompare.getSurname()) &&
			   (gender == toCompare.getGender());
	}
	 */

	/**
	 * Overload the 'not equals' operator
	 * @param   toCompare   The Person to compare with 'this' Person
	 * @return  bool        Are the Persons' data members different

	bool Person::operator!=(const Person& toCompare) const
	{
		return (!((*this) == toCompare)); // Use this object's equality operator for this
	}
	 */

	/**
	 * Overload the assignment operator
	 * @param   toAssignFrom   The Person whose data we will assign to 'this'
	 * @return  Person&        A reference to this object to allow cascading assignment
	 */
    Person& Person::operator=(const Person& toAssignFrom)
    {
    	// Test for self-assignment
    	if(this != &toAssignFrom)
    	{
    		// Objects are not at the same address so copy the values over
    		forename = toAssignFrom.getForename();
    		surname = toAssignFrom.getSurname();
    		gender = toAssignFrom.getGender();
    	}

    	// Return reference to this object to allow cascading assignment
    	return *this;
    }

    /**
     * Generate a string representation of this Person.
     * Note: This is NOT a usable serialize function
     * @return   string   The Person in string form
     */
	string Person::toString() const
	{
		// Use this objects outstream overload function
		stringstream ss; // The stream to output to
		ss << *this; // Output this object
		return ss.str(); // Convert the output stream to a string
	}

	/**
	 * Overload the out stream operator
	 * @param   os        The out stream to output into
	 * @param   person    The Person object to output
	 * @return  ostream&  A reference to the output stream to allow chaining
	 */
	ostream& operator<<(ostream& os, const Person& person)
	{
		// Output this person's name to the output stream
		os << person.forename + " " + person.surname;
		// Return a reference to the output stream used to allow chaining
		return os;
	}

} /* namespace Tom_F */
