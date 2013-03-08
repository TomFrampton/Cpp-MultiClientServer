/*
 * @file 	 TrainerQueue.h
 * @author	 Tom Frampton
 * @date 	 2013-02-25
 * @version  1.1
 * Copyright 2013 Tom Frampton
 */

/**
 * This class represents and controls the queue of trainers at a healthclub. Uses semaphores to maintain
 * thead safety between mutlitple training threads.
 */

#ifndef TRAINERQUEUE_H_
#define TRAINERQUEUE_H_

#include <pthread.h>
#include <Semaphore.h>
#include <queue>
#include <deque>

#include "Trainer.h"

using std::vector;
using std::deque;
using std::queue;

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
