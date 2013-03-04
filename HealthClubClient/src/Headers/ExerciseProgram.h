/*
 * ExerciseProgram.h
 *
 *  Created on: 4 Mar 2013
 *      Author: Tom
 */

#ifndef EXERCISEPROGRAM_H_
#define EXERCISEPROGRAM_H_

#include "Member.h"

namespace Tom_F {

class ExerciseProgram
{
	public:
		ExerciseProgram();
		virtual ~ExerciseProgram() = 0;

		virtual void exercise(Member& trainee) = 0;
	};

} /* namespace Tom_F */

#endif /* EXERCISEPROGRAM_H_ */
