/*
 * @file 	 ConsoleUI.h
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "CommunicationException.h"

#include "StringIntConverter.h"
#include "UserInterfaceIF.h"
#include "SimulationData.h"
#include "ConsoleUI.h"

using std::cout;
using std::cin;
using std::endl;

namespace Tom_F
{

	ConsoleUI::ConsoleUI() :
	consoleLock(PTHREAD_MUTEX_INITIALIZER),
	simulation(NULL)
	{
	}

	ConsoleUI::~ConsoleUI()
	{
		pthread_mutex_destroy(&consoleLock);
	}

	void ConsoleUI::printOutput(string output)
	{
		pthread_mutex_lock(&consoleLock);

		cout << output << endl;

		pthread_mutex_unlock(&consoleLock);
	}

	void ConsoleUI::startSimulation(SimulationControl& simulation)
	{
		this->simulation = &simulation;

		cout << "\n";
		cout << "Welcome to the Health Club client simulation" << endl;
		cout << "Copyright: Tom Frampton 2013" << endl;
		cout << "Version 1.0" << endl;
		cout << "\n";
		cout << "**********************************   " << endl;
		cout << "\n";
		cout << "1. Run Custom Simulation" << endl;
		cout << "2. Run 'Server Destroyer' Simulation" << endl;
		cout << "3. Quit Application" << endl;
		cout << "\n";

		bool inputAccepted = false;
		do
		{
			cout << "User> ";
			string input;
			getline(cin, input);

			if(input == "1")
			{
				inputAccepted = true;
				runCustomSimulation();
			}
			else if(input == "2")
			{
				inputAccepted = true;
				runSimulation(30, 1, 20);
			}
			else if(input == "3")
			{
				exit(0);
			}
			else
			{
				cout << "Input not recognised. Please try again" << endl;
			}
		}
		while(!inputAccepted);
	}

	void ConsoleUI::runSimulation(int runningTime, int arrivalInterval, int trainerCount)
	{
		try{
			cout << "\nStarting simulation with the following settings..\n" << endl;
			cout << "Trainers:                  " << trainerCount << endl;
			cout << "Arrival running time:      " << runningTime << " minutes" << endl;
			cout << "Arrivals on average every: " << arrivalInterval << " minutes" << endl;

			SimulationData data = simulation->run(runningTime, arrivalInterval, trainerCount);
			cout << "\n\n";
			cout << "Average waiting time: " << data.getAverageWaitingTime() << " minutes " << endl;
			cout << "Members enrolled:     " << data.getEnrolledCount() << endl;
			cout << "\n\n";
			cout << "Thankyou for running HealthyGym simulation" << endl;
			cout << "\n" << endl;
		}
		catch(Exception::CommunicationException& exp)
		{
			cout << "\n";
			cout << exp.getExplanation() << endl;
			cout << "\n";
			cout << "We are sorry but HealthyClub simulation had to end." << endl;
			cout << "\n";
		}

		getchar();
	}

	void ConsoleUI::runCustomSimulation()
	{
		string trainerNumberStr = "";
		string runningTimeStr = "";
		string intervalStr = "";

		int trainerNumber = 0;
		int runningTime = 0;
		int interval = 0;

		cout << "\n";
		cout << "Number of trainers:\n" << endl;

		bool accepted = false;
		do
		{
			cout << "User>";
			getline(cin, trainerNumberStr);

			if(isStringNumeric(trainerNumberStr))
			{
				trainerNumber = StringIntConverter::stringToInt(trainerNumberStr);
				if(trainerNumber > 0)
				{
					accepted = true;
				}
			}

			if(!accepted)
			{
				cout << "Invalid input. Please enter a number above 0" << endl;
			}
		}
		while(!accepted);

		cout << "\n";
		cout << "Arrival running time:\n" << endl;

		accepted = false;
		do
		{
			cout << "User>";
			getline(cin, runningTimeStr);

			if(isStringNumeric(runningTimeStr))
			{
				runningTime = StringIntConverter::stringToInt(runningTimeStr);
				if(runningTime > 0)
				{
					accepted = true;
				}
			}

			if(!accepted)
			{
				cout << "Invalid input. Please enter a number above 0" << endl;
			}
		}
		while(!accepted);

		cout << "\n";
		cout << "Average arrival interval:\n" << endl;

		accepted = false;
		do
		{
			cout << "User>";
			getline(cin, intervalStr);

			if(isStringNumeric(intervalStr))
			{
				interval = StringIntConverter::stringToInt(intervalStr);
				if(interval > 0)
				{
					accepted = true;
				}
			}

			if(!accepted)
			{
				cout << "Invalid input. Please enter a number above 0" << endl;
			}
		}
		while(!accepted);

		runSimulation(runningTime, interval, trainerNumber);


	}

	bool ConsoleUI::isStringNumeric(string input) const
	{
		bool isNumeric = true;
		unsigned int index = 0;
		while(index < input.size() && isNumeric)
		{
			isNumeric = isdigit(input[index]);
			index++;
		}
		return isNumeric;
	}

} /* namespace Tom_F */
