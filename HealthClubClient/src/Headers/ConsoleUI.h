/*
 * @file 	 ConsoleUI.h
 * @author	 Tom Frampton
 * @date 	 2013-02-09
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_

#include <pthread.h>

#include "UserInterfaceIF.h"

namespace Tom_F {

	class ConsoleUI : public UserInterfaceIF
	{
	public:
		ConsoleUI();
		virtual ~ConsoleUI();

		void printOutput(string output);
		/*string getUserInput(string promptMessage);*/

	private:
		pthread_mutex_t consoleLock;
	};

} /* namespace Tom_F */

#endif /* CONSOLEUI_H_ */
