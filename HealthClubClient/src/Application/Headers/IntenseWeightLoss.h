/*
 * IntenseWeightLoss.h
 *
 *  Created on: 4 Mar 2013
 *      Author: Tom
 */

#ifndef INTENSEWEIGHTLOSS_H_
#define INTENSEWEIGHTLOSS_H_

#include "Member.h"
#include "ExerciseProgram.h"

namespace Tom_F
{
	class IntenseWeightLoss : public ExerciseProgram {
	public:
		IntenseWeightLoss();
		virtual ~IntenseWeightLoss();

		void exercise(Member& trainee);
	};

} /* namespace Tom_F */

#endif /* INTENSEWEIGHTLOSS_H_ */
