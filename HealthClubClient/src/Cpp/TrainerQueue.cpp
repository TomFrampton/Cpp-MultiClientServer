/*
 * TrainerQueue.cpp
 *
 *  Created on: 25 Feb 2013
 *      Author: Tom
 */

#include <iostream>
#include "TrainerQueue.h"
#include <sstream>

using namespace std;

namespace Tom_F {

	TrainerQueue::TrainerQueue()
	{
		trainerQueue.push(Trainer());
		initSemaphores(1);
	}

	TrainerQueue::TrainerQueue(vector<Trainer> trainersToUse)
	{
		vector<Trainer>::iterator it = trainersToUse.begin();
		while(it != trainersToUse.end())
		{
			trainerQueue.push(*it);
			it++;
		}
		initSemaphores(trainersToUse.size());
	}

	TrainerQueue::~TrainerQueue() {
		// TODO Auto-generated destructor stub
	}

	Trainer TrainerQueue::getTrainer()
	{
		sem_wait(&available);
		sem_wait(&mutex);

		Trainer nextTrainer = trainerQueue.front();
		trainerQueue.pop();

		sem_post(&notAvailable);
		sem_post(&mutex);

		return nextTrainer;
	}

	void TrainerQueue::returnTrainer(Trainer trainer)
	{

		sem_wait(&notAvailable);
		sem_wait(&mutex);

		trainerQueue.push(trainer);

		sem_post(&available);
		sem_post(&mutex);
	}

	void TrainerQueue::initSemaphores(int numberOfTrainers)
	{
		sem_init(&mutex, 0, 1);
		sem_init(&available, 0, numberOfTrainers);
		sem_init(&notAvailable, 0, 0);
	}

} /* namespace Tom_F */
