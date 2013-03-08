/*
 * Trainer.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef TRAINER_H_
#define TRAINER_H_

#include <iostream>
#include <string>
#include <boost/serialization/base_object.hpp>

using std::ostream;
using std::string;

#include "Employee.h"
#include "Person.h"


namespace Tom_F
{
	class Trainer : public Employee
	{
	public:
		Trainer();
		Trainer(const Employee& toConvert);
		Trainer(const Trainer& toCopy);
		virtual ~Trainer();

	private:

		friend class boost::serialization::access;
		template<typename Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Employee>(*this);
		}

	};

} /* namespace Tom_F */

#endif /* TRAINER_H_ */
