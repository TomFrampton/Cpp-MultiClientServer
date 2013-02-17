/*
 * @file 	 SimulationControl.h
 * @author	 Tom Frampton
 * @date 	 2013-02-17
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#ifndef SIMULATIONCONTROL_H_
#define SIMULATIONCONTROL_H_

#include "ClientConnectionControl.h"
#include "ClientMessenger.h"

namespace Tom_F
{

	class SimulationControl
	{
	public:
		SimulationControl();
		virtual ~SimulationControl();

		void run();
	};

} /* namespace Tom_F */

#endif /* SIMULATIONCONTROL_H_ */
