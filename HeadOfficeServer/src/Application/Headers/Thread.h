/*
 * Thread.h
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
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
		virtual void threadStart() = 0;

	private:
		// The handler to the thread
		pthread_t thread;
		// No 'this' parameter so this is a valid POSIX thread function
		static void* threadFunction(void* callingThread);
	};

} /* namespace Tom_F */

#endif /* THREAD_H_ */
