/*
 * InvalidMemberException.h
 *
 *  Created on: 26 Feb 2013
 *      Author: Tom
 */

#ifndef INVALIDMEMBEREXCEPTION_H_
#define INVALIDMEMBEREXCEPTION_H_

#include <exception>
#include <string>

using std::string;

namespace Tom_F
{
	namespace Exception
	{
		class InvalidMemberException : public std::exception
		{
		public:
			InvalidMemberException();
			InvalidMemberException(int membershipID, string explanation);
			virtual ~InvalidMemberException() throw();

			int getMembershipID() const;
			string getExplanation() const;

		private:
			int membershipID;
			string explanation;
		};

	} /* namespace exception */

} /* namespace Tom_F */

#endif /* INVALIDMEMBEREXCEPTION_H_ */
