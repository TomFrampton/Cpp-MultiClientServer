/*
 * HealthClubMapper.h
 *
 *  Created on: 27 Feb 2013
 *      Author: Tom
 */

#ifndef HEALTHCLUBMAPPER_H_
#define HEALTHCLUBMAPPER_H_

namespace Tom_F {

	class HealthClubMapper
	{
	public:
		HealthClubMapper();
		virtual ~HealthClubMapper();

		int addToDatabase(DBControlIF& db) const;
	};

} /* namespace Tom_F */
#endif /* HEALTHCLUBMAPPER_H_ */
