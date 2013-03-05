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
		// TODO Auto-generated constructor stub
	}

	ConsoleUI::~ConsoleUI()
	{
		// destroy mutex
	}

	void ConsoleUI::printOutput(string output)
	{
		pthread_mutex_lock(&consoleLock);

		cout << output << endl;

		pthread_mutex_unlock(&consoleLock);
	}

/*
	string ConsoleUI::getUserInput(string promptMessage)
	{
		pthread_mutex_lock(&consoleLock);

		cout << promptMessage + ":" << endl;
		string userInput;
		cin >> userInput;

		pthread_mutex_unlock(&consoleLock);

		return userInput;
	}
*/

} /* namespace Tom_F */
