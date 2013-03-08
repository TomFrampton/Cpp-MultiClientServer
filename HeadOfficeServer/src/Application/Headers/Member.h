/*
 * Member.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef MEMBER_H_
#define MEMBER_H_

#include <boost/serialization/base_object.hpp>
#include "Person.h"
#include "Guest.h"

namespace Tom_F
{
	class Member : public Customer
	{
		public:
			Member();
			Member(const Member& toCopy);
			Member(int membershipID, const Guest& enrolled);
			virtual ~Member();

			void setMembershipID(int id);
			int getMembershipID() const;

			string toString() const;
			friend ostream& operator<<(ostream& os, const Member& member);

		private:
			int membershipID;

			friend class boost::serialization::access;
			template<class Archive>
			void serialize(Archive& ar, const unsigned int version)
			{
				ar & boost::serialization::base_object<Customer>(*this);
				ar & membershipID;
			}

		};

} /* namespace Tom_F */

#endif /* MEMBER_H_ */
