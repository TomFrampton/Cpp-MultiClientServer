/*
 * @file 	 SimulationControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-17
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include <string>

#include "ConsoleUI.h"
#include "HealthClubAdmin.h"
#include "Reception.h"
#include "Guest.h"
#include "PersonGenerator.h"
#include "GuestGenerator.h"
#include "UserInterfaceIF.h"
#include "SimulationControl.h"

namespace Tom_F
{

	SimulationControl::SimulationControl() :
	arrivalGenerator(NULL),
	userInterface(NULL)
	{
	}

	SimulationControl::SimulationControl(UserInterfaceIF* userInterface) :
	arrivalGenerator(NULL),
	userInterface(userInterface)
	{

	}

	SimulationControl::~SimulationControl()
	{
	}

	SimulationData SimulationControl::run(int runningTime, int arrivalInterval, int trainerCount)
	{
		ClientConnectionControl connectionControl;
		ClientMessenger messenger(&connectionControl);
		ConsoleUI userInterface;
		HealthClubAdmin admin(&messenger, &userInterface);
		PoissonArrivalGenerator arrivalGenerator(runningTime, arrivalInterval);
		PersonGenerator personGen;
		GuestGenerator guestGen(personGen);

		connectionControl.connectToHeadOffice();

		TrainerQueue trainers = admin.setupHealthClub(personGen, trainerCount);


		Reception reception(&admin, &trainers);

		// Get the number of arrival slots that the generator has generated
		int arrivalSlotsSize = arrivalGenerator.getArrivalCount();
		// For each slot
		for(int i = 0; i < arrivalSlotsSize; i++)
		{
			if(arrivalGenerator.hasArrived()) // Someone has arrived
			{
				Guest arrival = guestGen.generateGuest(); // Generate them
				reception.arrive(arrival); // Arrive at reception
			}
			Sleep(1000); // Sleep for a second (1 min in simulator time)
		}

		SimulationData data = reception.close();
		connectionControl.disconnect();
		return data;
	}

} /* namespace Tom_F */
