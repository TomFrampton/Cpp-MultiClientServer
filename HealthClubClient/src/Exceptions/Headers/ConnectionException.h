/*
 * ConnectionException.h
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
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
			string explanation;
		};

	} /* namespace Exception */

} /* namespace Tom_F */

#endif /* CONNECTIONEXCEPTION_H_ */
