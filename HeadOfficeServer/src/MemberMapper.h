/*
 * MemberMapper.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef MEMBERMAPPER_H_
#define MEMBERMAPPER_H_

#include "Guest.h"
#include "DBControl.h"

namespace Tom_F
{
	class MemberMapper
	{
	public:
		MemberMapper();
		virtual ~MemberMapper();

		int addMemberToDatabase(const Guest& newMember) const;

	};

} /* namespace Tom_F */
#endif /* MEMBERMAPPER_H_ */
