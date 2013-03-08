/*
 * Reception.cpp
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */


#include <stdio.h>

#include "CommunicationException.h"

#include "Reception.h"
#include "Member.h"

namespace Tom_F {

	Reception::Reception() :
	admin(NULL),
	trainers(NULL)
	{

	}

	Reception::Reception(HealthClubAdmin* admin, TrainerQueue* trainers) :
	admin(admin),
	trainers(trainers)
	{
	}

	Reception::~Reception()
	{
	}

	/**
	 * Simulates the arrival of a guest to the health club.
	 * @param   arrival   The guest that has just arrived
	 */
	void Reception::arrive(Guest& arrival)
	{
		try
		{
			// Enrol the member and save the object on the heap using shared pointers
			boost::shared_ptr<Member> enrolled(new Member(admin->enrolMember(arrival)));
			members.push_back(enrolled); // Store the enrolled member
			// Same for the training object
			boost::shared_ptr<TrainingControl> training(new TrainingControl(enrolled, trainers, admin));
			trainingThreads.push_back(training); // Store the training threads so we can join() later
			training->runThread(); // Start the training thread
		}
		catch (Exception::CommunicationException&) // There was an error communicating with the server
		{
			// Admin will handle informing the user - just don't do anything with this arrival
		}
	}

	SimulationData Reception::close()
	{
		vector<shared_ptr<TrainingControl> >::iterator it = trainingThreads.begin();

		while(it != trainingThreads.end())
		{
			shared_ptr<TrainingControl> threadPtr = *it;
			threadPtr->waitForThread();
			it++;
		}

		return admin->getSimulationData();
	}

} /* namespace Tom_F */
