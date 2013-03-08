/*
 * DatabaseException.h
 *
 *  Created on: 6 Mar 2013
 *      Author: Tom
 */

#ifndef DATABASEEXCEPTION_H_
#define DATABASEEXCEPTION_H_

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace Tom_F
{
	namespace Exception
	{
		class DatabaseException : public exception
		{
		public:
			DatabaseException() throw();
			DatabaseException(string explanation) throw();
			virtual ~DatabaseException() throw();

			string getExplanation() const;

		private:
			string explanation;
		};

	} /* namespace Exception */

} /* namespace Tom_F */

#endif /* DATABASEEXCEPTION_H_ */
