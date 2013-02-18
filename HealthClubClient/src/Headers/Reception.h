/*
 * Reception.h
 *
 *  Created on: 18 Feb 2013
 *      Author: Tom
 */

#ifndef RECEPTION_H_
#define RECEPTION_H_

#include "ClientMessenger.h"
//#include "Guest.h"

namespace Tom_F
{

	class Reception
	{
	public:
		Reception(const ClientMessenger* const messenger);
		virtual ~Reception();

		void arrive(Guest arrival);

	private:
		const ClientMessenger* const messenger;
	};

} /* namespace Tom_F */

#endif /* RECEPTION_H_ */
