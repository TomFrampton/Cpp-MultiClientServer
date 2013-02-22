/*
 * Member.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef MEMBER_H_
#define MEMBER_H_

namespace Tom_F
{
	class Member : public Person
	{
		public:
			Member();
			Member(int membershipNo);
			virtual ~Member();

			int getMembershipNo() const;

		private:
			const int membershipNo;

			friend class boost::serialization::access;
			template<class Archive>
			void serialize(Archive& ar, const unsigned int version)
			{
				ar & boost::serialization::base_object<Person>(*this);
				ar & membershipNo;
			}

		};

} /* namespace Tom_F */

#endif /* MEMBER_H_ */
