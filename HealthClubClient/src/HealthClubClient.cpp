//============================================================================
// Name        : HealthClubClient.cpp
// Author      : Tom Frampton
// Version     :
// Copyright   : Copyright Tom Frampton 2013
// Description : Represents a local health club that will connect to the
// 				 company's head office server
//============================================================================
#include "AbstractUI.h"
#include "ConsoleUI.h"
#include "SimulationControl.h"

using namespace Tom_F;

int main() {

	SimulationControl simulation;
	simulation.run();

	return 0;
}
