/*
 * @file 	 ConnectionException.h
 * @author	 Tom Frampton
 * @date 	 2013-03-06
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This exception is thrown when there is an error setting up the server's
 * connection. For example, a bind or listening error.
 */
#ifndef CONNECTIONEXCEPTION_H_
#define CONNECTIONEXCEPTION_H_

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace Tom_F
{
	namespace Exception
	{
		class ConnectionException : public exception
		{
		public:
			ConnectionException() throw();
			ConnectionException(string explanation) throw();
			virtual ~ConnectionException() throw();

			string getExplanation() const;

		private:
			string explanation; // More detail about the exception
		};

	} /* namespace Exception */

} /* namespace Tom_F */

#endif /* CONNECTIONEXCEPTION_H_ */
