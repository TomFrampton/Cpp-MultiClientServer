/*
 * Employee.h
 *
 *  Created on: 27 Feb 2013
 *      Author: Tom
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <Person.h>

#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>

namespace Tom_F
{
	class Employee : public Person
	{
	public:
		Employee();
		Employee(const Employee& toCopy);
		Employee(int employeeID, Person& hired);
		virtual ~Employee();

		int getEmployeeID() const;

	private:
		int employeeID;

		friend class boost::serialization::access;
		template<typename Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Person>(*this);
			ar & employeeID;
		}
	};

} /* namespace Tom_F */
#endif /* EMPLOYEE_H_ */
