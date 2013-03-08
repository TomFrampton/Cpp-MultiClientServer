//============================================================================
// Name        : HeadOfficeServer.cpp
// Author      : Tom Frampton
// Version     :
// Copyright   : Copyright Tom Frampton 2013
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>

#include "DatabaseException.h"
#include "ConnectionException.h"

#include "DBControl.h"
#include "HeadOfficeAdmin.h"
#include "ServerConnectionControl.h"
#include "ConsoleUI.h"

using namespace Tom_F;

int main()
{

	ConsoleUI userInterface; // Create user interface
	try
	{
		DBControl db;  // Create database wrapper
		HeadOfficeAdmin admin(&db, &userInterface); // Main admin object
		ServerConnectionControl server(&admin); // Server connection class
		userInterface.startServer(server); // Start the application by getting user input
	}
	catch(Exception::DatabaseException& exc) // Error with database connection
	{
		userInterface.printOutput(exc.getExplanation()); // Print explanation
	}
	catch(Exception::ConnectionException& exc) // Error with the server's connection
	{
		userInterface.printOutput(exc.getExplanation()); // Print explanation
	}
	// Print fatal error message
	userInterface.printOutput("\nFatal server error. Server must close");
	getchar(); // Wait for user input

	return 0;
}
