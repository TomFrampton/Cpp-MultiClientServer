/*
 * @file 	 SimulationControl.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-17
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include "SimulationControl.h"
#include "Reception.h"
#include "Guest.h"

#include <iostream>
#include <string>

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
		//messenger.listenForClientInput();

		Reception reception(&messenger);

		while(true)
		{
			std::string input;;
			std::cin >> input;

			Guest tom;

			if(input == "arrive")
			{
				reception.arrive(tom);
			}
		}


	}

} /* namespace Tom_F */
