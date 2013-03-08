/*
 * Thread.cpp
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#include "Thread.h"

namespace Tom_F {

	Thread::Thread()
	{
	}

	Thread::~Thread()
	{
	}

	/**
	 * Creates and runs a new thread for this class
	 * @return   int   Show if the thread was created without error
	 */
	int Thread::runThread()
	{
		/* Create the thread by calling the static thread function and send 'this'
		 * so it knows which object it was */
		return (pthread_create(&thread, NULL , threadFunction, this) == 0);
	}

	/**
	 * Wait for the thread to join()
	 */
	void Thread::waitForThread()
	{
		pthread_join(thread, NULL);
	}

	/**
	 * POSIX style threadFunction that is called when the new thread is started.
	 * @param   callingThread   Pointer to the object that called this method
	 * @return  void*  			A null pointer
	 */
	void* Thread::threadFunction(void* callingThread)
	{
		/* Cast the calling object pointer to a pointer of a Thread
		 * and call it's threadStart() function. This will have been
		 * implemented by the subclass to customise what happens when
		 * the thread starts
		 */
		static_cast<Thread*>(callingThread)->threadStart();
		return 0;
	}

} /* namespace Tom_F */
