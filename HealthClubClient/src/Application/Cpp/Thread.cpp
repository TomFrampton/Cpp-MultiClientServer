/*
 * @file 	 Thread.cpp
 * @author	 Tom Frampton
 * @date 	 2013-03-04
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * A wrapper class for a POSIX thread. Encapsulates all the complexity of starting a new thread.
 * Extended by any class that wants to run on it's own thread.
 */

#include "Thread.h"

namespace Tom_F
{
	/**
	 * Default constructor.
	 */
	Thread::Thread()
	{
	}

	/**
	 * Destructor.
	 */
	Thread::~Thread()
	{
	}

	/**
	 * Creates and runs the POSIX thread.
	 * @return   int   The result of the thread startup
	 */
	int Thread::runThread()
	{
		// Create a pthread by calling threadFunction() passing it a pointer to this object
		return (pthread_create(&thread, NULL, threadFunction, this) == 0);
	}

	/**
	 * Wait for this thread to join
	 */
	void Thread::waitForThread()
	{
		pthread_join(thread, NULL);
	}

	/**
	 * The thread function that is called when a thread is created. A function with this header
	 * is a requirement of in POSIX. Casts the calling thread pointer to a Thread* and calls
	 * it's threadStart() method which will have been implemented by the subclass.
	 * @param   callingThread   A pointer to the object that called this function
	 */
	void* Thread::threadFunction(void* callingThread)
	{
		static_cast<Thread*>(callingThread)->threadStart(); // Casts the calling object* to a Thread*
		return 0; // Return success
	}

} /* namespace Tom_F */
