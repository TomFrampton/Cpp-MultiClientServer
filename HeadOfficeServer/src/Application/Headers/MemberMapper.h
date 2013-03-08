/*
 * MemberMapper.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef MEMBERMAPPER_H_
#define MEMBERMAPPER_H_

#include "Guest.h"
#include "DBControlIF.h"
#include "Member.h"

namespace Tom_F
{
	class MemberMapper
	{
	public:
		MemberMapper();
		virtual ~MemberMapper();

		int addToDatabase(DBControlIF& db, const Guest& newMember, int healthClubID) const;
		int getMemberCount(DBControlIF& db, int healthClubID) const;
		Member getMemberByID(DBControlIF& db, int membershipID) const;

	private:
		Member fromRow(MYSQL_ROW row) const;

	};

} /* namespace Tom_F */
#endif /* MEMBERMAPPER_H_ */
