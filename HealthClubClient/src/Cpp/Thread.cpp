/*
 * Thread.cpp
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */
#include "debug.h"
#include "Thread.h"

namespace Tom_F {

	Thread::Thread()
	{
		// TODO Auto-generated constructor stub
	}

	Thread::~Thread()
	{
		// TODO Auto-generated destructor stub
	}

	int Thread::runThread()
	{
		return (pthread_create(&thread, NULL, threadFunction, this) == 0);
	}

	void Thread::waitForThread()
	{
		pthread_join(thread, NULL);
	}

	void* Thread::threadFunction(void* callingThread)
	{
		static_cast<Thread*>(callingThread)->threadStart();
		return 0;
	}

} /* namespace Tom_F */
