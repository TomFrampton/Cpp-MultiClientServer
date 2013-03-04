/*
 * PersonGenerator.h
 *
 *  Created on: 3 Mar 2013
 *      Author: Tom
 */

#ifndef PERSONGENERATOR_H_
#define PERSONGENERATOR_H_

#include <vector>
#include "Person.h"

using std::vector;

namespace Tom_F
{
	class PersonGenerator
	{
	public:
		PersonGenerator();
		virtual ~PersonGenerator();

		Person generatePerson();

	private:
		vector<string> maleForenames;
		vector<string> femaleForenames;
		vector<string> surnames;
	};

} /* namespace Tom_F */

#endif /* PERSONGENERATOR_H_ */
