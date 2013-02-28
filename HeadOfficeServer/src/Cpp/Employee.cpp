/*
 * Employee.cpp
 *
 *  Created on: 27 Feb 2013
 *      Author: Tom
 */

#include "Employee.h"

namespace Tom_F {

	Employee::Employee()
	{
		// TODO Auto-generated constructor stub
	}

	Employee::Employee(const Employee& toCopy) :
	Person(toCopy),
	employeeID(toCopy.getEmployeeID())
	{
	}

	Employee::Employee(int employeeID, Person& hired) :
	Person(hired),
	employeeID(employeeID)
	{
	}

	Employee::~Employee()
	{
		// TODO Auto-generated destructor stub
	}

	int Employee::getEmployeeID() const
	{
		return employeeID;
	}

} /* namespace Tom_F */
