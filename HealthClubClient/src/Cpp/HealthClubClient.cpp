//============================================================================
// Name        : HealthClubClient.cpp
// Author      : Tom Frampton
// Version     :
// Copyright   : Copyright Tom Frampton 2013
// Description : Represents a local health club that will connect to the
// 				 company's head office server
//============================================================================
#include "ConsoleUI.h"
#include "SimulationControl.h"
#include "PoissonArrivalGenerator.h"
#include "SimulationData.h"
#include <stdio.h>

using namespace Tom_F;

int main() {

	ConsoleUI ui;
	SimulationControl simulation(&ui);
	ui.startSimulation(simulation);

	return 0;
}
