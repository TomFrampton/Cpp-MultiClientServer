/*
 * @file 	 Thread.h
 * @author	 Tom Frampton
 * @date 	 2013-03-04
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * A wrapper class for a POSIX thread. Encapsulates all the complexity of starting a new thread.
 * Extended by any class that wants to run on it's own thread.
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

namespace Tom_F
{
	class Thread
	{
	public:
		Thread();
		virtual ~Thread();

		int runThread();
		void waitForThread();

	protected:
		virtual void threadStart() = 0; // The thread function. The subclass will implement this method

	private:
		pthread_t thread;
		// Thread starting function. Must be static as it cannot have a 'this' parameter
		static void* threadFunction(void* callingThread);

	};

} /* namespace Tom_F */
#endif /* THREAD_H_ */
