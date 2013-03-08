/*
 * EmployeeMapper.h
 *
 *  Created on: 28 Feb 2013
 *      Author: Tom
 */

#ifndef EMPLOYEEMAPPER_H_
#define EMPLOYEEMAPPER_H_

#include <string>
#include "Person.h"

using std::string;

namespace Tom_F {

	class EmployeeMapper
	{
	public:
		EmployeeMapper();
		virtual ~EmployeeMapper();

		int addToDatabase(DBControlIF& db, const Person& toHire, string position, int healthClubID) const;
	};

} /* namespace Tom_F */
#endif /* EMPLOYEEMAPPER_H_ */
