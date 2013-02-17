/*
 * @file 	 SimulationControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-17
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include "SimulationControl.h"

namespace Tom_F
{

	SimulationControl::SimulationControl()
	{
		// TODO Auto-generated constructor stub

	}

	SimulationControl::~SimulationControl()
	{
		// TODO Auto-generated destructor stub
	}

	void SimulationControl::run()
	{
		ClientConnectionControl client;
		client.connectToHeadOffice();

		ClientMessenger messenger(client);
		messenger.listenForInput();
	}

} /* namespace Tom_F */
