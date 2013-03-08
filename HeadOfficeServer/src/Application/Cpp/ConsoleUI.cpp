/*
 * @file 	 ConsoleUI.h
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include <iostream>
#include "ConsoleUI.h"
#include "UserInterfaceIF.h"

using std::cout;
using std::cin;
using std::endl;

namespace Tom_F
{

	ConsoleUI::ConsoleUI() :
	consoleLock(PTHREAD_MUTEX_INITIALIZER)
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

	void ConsoleUI::startServer(ServerConnectionControl& serverControl)
	{
		cout << "\n";
		cout << "Welcome to the Head Office server" << endl;
		cout << "Copyright: Tom Frampton 2013" << endl;
		cout << "Version 1.0" << endl;
		cout << "\n";
		cout << "**********************************   " << endl;
		cout << "\n";
		cout << "1. Run Server" << endl;
		cout << "2. Quit Application" << endl;
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
			}
			else if(input == "2")
			{
				exit(0);
			}
			else
			{
				cout << "Input not recognised. Please try again" << endl;
			}
		}
		while(!inputAccepted);

		int connectionNumber = selectConnectionCount();
		cout << "\n";
		cout << "Server started with " << connectionNumber << " connection sockets." << endl;
		cout << "\n";
		cout << "Server listening..." << endl;
		cout << "\n\n";
		serverControl.run(connectionNumber);
	}

	int ConsoleUI::selectConnectionCount() const
	{
		cout << "\n";
		cout << "Enter maximum number of simultaneous connections." << endl;
		cout << "\n";

		int connectionNumber = 0;
		bool inputAccepted = false;
		do
		{
			cout << "User> ";
			string input;
			getline(cin, input);

			if(isStringNumeric(input))
			{
				connectionNumber = atoi(input.c_str());
				inputAccepted = true;
			}
			else
			{
				cout << "Input not recognised. Please try again" << endl;
			}
		}
		while(!inputAccepted);

		return connectionNumber;
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
