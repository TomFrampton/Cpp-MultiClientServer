/*
 * @file 	 SimulationControl.h
 * @author	 Tom Frampton
 * @date 	 2013-02-17
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#ifndef SIMULATIONCONTROL_H_
#define SIMULATIONCONTROL_H_

#include "PoissonArrivalGenerator.h"
#include "ClientConnectionControl.h"
#include "ClientMessenger.h"
#include "SimulationData.h"
#include "UserInterfaceIF.h"


namespace Tom_F
{
	class SimulationControl
	{
	public:
		SimulationControl();
		SimulationControl(UserInterfaceIF* userInterface);
		virtual ~SimulationControl();

		SimulationData run(int runningTime, int arrivalInterval, int trainerCount);

	private:
		PoissonArrivalGenerator* const arrivalGenerator;
		UserInterfaceIF* const userInterface;
	};

} /* namespace Tom_F */

#endif /* SIMULATIONCONTROL_H_ */
