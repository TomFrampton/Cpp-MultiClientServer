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

#include "TrainerQueue.h"

namespace Tom_F {

	/**
	 * Default constructor. Starts up the trainer queue with a single default trainer.
	 */
	TrainerQueue::TrainerQueue()
	{
		trainerQueue.push(Trainer()); // Add a trainer to the queue
		initSemaphores(1); // Initialize the semaphores to use a queue with a single trainer
	}

	/**
	 * Constructs the trainer queue using a collection of trainers.
	 * @param   trainersToUse   The trainer objects that will be added to the trainer queue.
	 */
	TrainerQueue::TrainerQueue(vector<Trainer> trainersToUse)
	{
		vector<Trainer>::iterator it = trainersToUse.begin(); // Get an iterator for the vector of trainers
		while(it != trainersToUse.end()) // For all trainers
		{
			trainerQueue.push(*it); // Add trainer to trainer queue
			it++;
		}
		initSemaphores(trainersToUse.size()); // Initialize the semaphores to use a trainer queue of this size
	}

	/**
	 * Destructor. Destroy the semaphores.
	 */
	TrainerQueue::~TrainerQueue()
	{
		sem_destroy(&mutex);
		sem_destroy(&available);
		sem_destroy(&notAvailable);
	}

	/**
	 * Try to get a trainer from the queue. If there are no trainers available the thread will sleep until
	 * one becomes available.
	 * @return The trainer that was taken from the queue
	 */
	Trainer TrainerQueue::getTrainer()
	{
		sem_wait(&available); // Proceed on the condition that there are trainers available
		sem_wait(&mutex); // Lock the critical section

		Trainer nextTrainer = trainerQueue.front(); // Get the first trainer
		trainerQueue.pop();

		sem_post(&mutex); // Unlock critical section
		//sem_post(&notAvailable); // Post on the not available semaphore because one there is one less trainer

		return nextTrainer;
	}

	/**
	 * Once a trainer has completed a trainer meeting with a customer this method is called to put the trainer
	 * back into the queue.
	 * @param   trainer   The trainer that is to be returned to the waiting queue
	 */
	void TrainerQueue::returnTrainer(Trainer trainer)
	{
		//sem_wait(&notAvailable); // Proceed on condition that there are slots in the queue available
								 // Should always proceed as there can't be more trainers than slots in the queue
		sem_wait(&mutex); // Lock the critical section

		trainerQueue.push(trainer); // Add trainer to queue

		sem_post(&mutex); // Unlock the critical section
		sem_post(&available); // Post on the available semaphore because there is one more trainer available.
	}

	/**
	 * Initializes the semaphores based on the number of trainers in the queue.
	 * @param   numberOfTrainers   The number of trainers to be used.
	 */
	void TrainerQueue::initSemaphores(int numberOfTrainers)
	{
		sem_init(&mutex, 0, 1); // mutex is a binary semaphore - either critical section is locked or unlocked
		sem_init(&available, 0, numberOfTrainers); // All trainers available so initilze with value numberOfTrainers
		//sem_init(&notAvailable, 0, 0); // No trainers not available so initialize to 0
	}

} /* namespace Tom_F */
