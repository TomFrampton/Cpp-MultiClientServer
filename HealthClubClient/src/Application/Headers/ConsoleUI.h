/*
 * @file 	 ConsoleUI.h
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_

#include <pthread.h>

#include "SimulationControl.h"
#include "UserInterfaceIF.h"

namespace Tom_F {

	class ConsoleUI : public UserInterfaceIF
	{
	public:
		ConsoleUI();
		virtual ~ConsoleUI();

		void printOutput(string output);
		void startSimulation(SimulationControl& simulation);

	private:
		pthread_mutex_t consoleLock;
		SimulationControl* simulation;

		void runCustomSimulation();
		void runSimulation(int runningTime, int arrivalInterval, int trainerCount);
		bool isStringNumeric(string input) const;
	};

} /* namespace Tom_F */

#endif /* CONSOLEUI_H_ */
