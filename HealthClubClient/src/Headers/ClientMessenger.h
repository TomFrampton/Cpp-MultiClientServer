/*
 * @file 	 ClientMessenger.h
 * @author	 Tom Frampton
 * @date 	 2013-02-14
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * Responsible for translating method calls into a Message object and serializing to a char*
 * to be send across the network.
 */

#ifndef CLIENTMESSENGER_H_
#define CLIENTMESSENGER_H_

#include "ClientConnectionControl.h"
#include "Guest.h"

namespace Tom_F {

class ClientMessenger
{
	public:
		ClientMessenger(const ClientConnectionControl& connectionControl);
		virtual ~ClientMessenger();

		void listenForClientInput();
		void listenForServerInput();

		void enrolMember(Guest& newMember) const;

	private:
		const ClientConnectionControl& connectionControl;

	};

} /* namespace Tom_F */
#endif /* CLIENTMESSENGER_H_ */
