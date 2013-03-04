/*
 * TrainerQueue.h
 *
 *  Created on: 25 Feb 2013
 *      Author: Tom
 */

#ifndef TRAINERQUEUE_H_
#define TRAINERQUEUE_H_

#include "Trainer.h"
#include <pthread.h>
#include <Semaphore.h>
#include <queue>
#include <deque>

using namespace std;

namespace Tom_F {

	class TrainerQueue
	{
	public:
		TrainerQueue();
		TrainerQueue(vector<Trainer> trainersToUse);
		virtual ~TrainerQueue();

		Trainer getTrainer();
		void returnTrainer(Trainer trainer);

	private:
		sem_t mutex;
		sem_t available;
		sem_t notAvailable;

		queue<Trainer, deque<Trainer> > trainerQueue;

		void initSemaphores(int numberOfTrainers);
	};

} /* namespace Tom_F */
#endif /* TRAINERQUEUE_H_ */
