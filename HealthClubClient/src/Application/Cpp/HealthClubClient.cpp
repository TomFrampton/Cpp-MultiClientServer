//============================================================================
// Name        : HealthClubClient.cpp

// Author      : Tom Frampton
// Version     :
// Copyright   : Copyright Tom Frampton 2013
// Description : Represents a local health club that will connect to the
// 				 company's head office server
//============================================================================

#include "CommunicationException.h"
#include "ConnectionException.h"

#include "ConsoleUI.h"
#include "SimulationControl.h"
#include "PoissonArrivalGenerator.h"
#include "SimulationData.h"
#include <stdio.h>

using namespace Tom_F;

int main() {

	ConsoleUI userInterface;

	try
	{
		SimulationControl simulation(&userInterface);
		userInterface.startSimulation(simulation);
	}
	catch(Exception::CommunicationException& exc) // Error with communicating with server
	{
		userInterface.printOutput(exc.getExplanation()); // Print explanation
	}
	catch(Exception::ConnectionException& exc) // Error with the client's connection
	{
		userInterface.printOutput(exc.getExplanation()); // Print explanation
	}
	// Print fatal error message
	userInterface.printOutput("\nFatal server error. Server must close");
	getchar(); // Wait for user input
	return 0;
}
