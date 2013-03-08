/*
 * Trainer.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#include "Trainer.h"

namespace Tom_F {

	Trainer::Trainer()
	{
	}

	Trainer::Trainer(const Trainer& toCopy) :
	Employee(toCopy)
	{
	}

	Trainer::Trainer(const Employee& toConvert) :
	Employee(toConvert)
	{
	}

	Trainer::~Trainer()
	{
	}

} /* namespace Tom_F */
