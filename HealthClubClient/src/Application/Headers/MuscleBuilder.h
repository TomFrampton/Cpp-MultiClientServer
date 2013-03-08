/*
 * MuscleBuilder.h
 *
 *  Created on: 4 Mar 2013
 *      Author: Tom
 */

#ifndef MUSCLEBUILDER_H_
#define MUSCLEBUILDER_H_

#include "Member.h"
#include "ExerciseProgram.h"

namespace Tom_F
{
	class MuscleBuilder : public ExerciseProgram
	{
	public:
		MuscleBuilder();
		virtual ~MuscleBuilder();

		void exercise(Member& trainee);
	};
} /* namespace Tom_F */

#endif /* MUSCLEBUILDER_H_ */
