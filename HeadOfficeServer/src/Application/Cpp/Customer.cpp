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
	weight(0)
	{
	}

	Customer::Customer(const Customer& toCopy) :
	Person(toCopy),
	height(toCopy.getHeight()),
	weight(toCopy.getWeight())
	{
	}

	Customer::Customer(const Person& toConvert, int height, int weight) :
	Person(toConvert),
	height(height),
	weight(weight)
	{
	}

	Customer::Customer(string forename, string surname, char gender, int height, int weight) :
	Person(forename, surname, gender),
	height(height),
	weight(weight)
	{
	}

	Customer::~Customer()
	{
	}

	void Customer::setHeight(int height)
	{
		this->height = height;
	}

	void Customer::setWeight(int weight)
	{
		this->weight = weight;
	}

	int Customer::getHeight() const
	{
		return height;
	}

	int Customer::getWeight() const
	{
		return weight;
	}

} /* namespace Tom_F */
