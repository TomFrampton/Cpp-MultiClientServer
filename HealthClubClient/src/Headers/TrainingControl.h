/*
 * TrainingControl.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef TRAININGCONTROL_H_
#define TRAININGCONTROL_H_

namespace Tom_F {

class TrainingControl
{
	public:
		TrainingControl();
		virtual ~TrainingControl();

		//void train(Member member);

	private:
		void preMeeting();
		void training();
		void postMeeting();
	};

} /* namespace Tom_F */

#endif /* TRAININGCONTROL_H_ */
