/*
 * CommunicationException.h
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
 */

#ifndef COMMUNICATIONEXCEPTION_H_
#define COMMUNICATIONEXCEPTION_H_

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace Tom_F
{
	namespace Exception
	{
		class CommunicationException : public exception
		{
		public:
			CommunicationException() throw();
			CommunicationException(string explanatation) throw();
			virtual ~CommunicationException();

			string getExplanation() const;

		private:
			string explanation;
		};

	} /* namespace Exception */

} /* namespace Tom_F */

#endif /* COMMUNICATIONEXCEPTION_H_ */
