/*
 * Customer.cpp
 *
 *  Created on: 26 Feb 2013
 *      Author: Tom
 */

#include "Customer.h"

namespace Tom_F
{
	Customer::Customer() :
	Person(),
	height(0),
	weight(0),
	bodyFatPC(0)
	{
		// TODO Auto-generated constructor stub
	}

	Customer::Customer(string forename, string surname, int height, int weight, double bodyFatPC) :
	Person(forename, surname),
	height(height),
	weight(weight),
	bodyFatPC(bodyFatPC)
	{
		// TODO Auto-generated constructor stub
	}

	Customer::~Customer()
	{
		// TODO Auto-generated destructor stub
	}

	int Customer::getHeight() const
	{
		return height;
	}

	int Customer::getWeight() const
	{
		return weight;
	}

	double Customer::getBodyFatPC() const
	{
		return bodyFatPC;
	}

} /* namespace Tom_F */
