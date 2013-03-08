/*
 * @file 	 ServerMessenger.h
 * @author	 Tom Frampton
 * @date 	 2013-02-14
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This class is reponsible for identifying char* messages passed over the network, unserializing any objects,
 * and calling the appropriate methods on the server side.
 */

#ifndef SERVERMESSENGER_H_
#define SERVERMESSENGER_H_

#include <string>
#include "Serializer.h"
#include "Message.h"
#include "ConnectionHandler.h"
#include "HeadOfficeAdmin.h"

using std::string;

namespace Tom_F
{
	class ServerMessenger
	{
	public:
		ServerMessenger();
		ServerMessenger(ConnectionHandler* connection, const HeadOfficeAdmin* admin);
		virtual ~ServerMessenger();

		void processInput(string input) const;

	private:
		const ConnectionHandler* const connection;
		const HeadOfficeAdmin* const admin;
		Serializer serializer;

		void registerHealthClub(Message& received) const;
		void enrolMember(Message& received) const;
		void logHealthData(Message& received) const;
		void getLastHealthLog(Message& received) const;
		void hireEmployee(Message& received) const;
		void logTrainingMeeting(Message& received) const;
		void getSimulationData(Message& received) const;
	};

} /* namespace Tom_F */

#endif /* SERVERMESSENGER_H_ */
