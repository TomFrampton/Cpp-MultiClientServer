/*
 * @file 	 ServerMessenger.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-14
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include <boost/serialization/vector.hpp>
#include <string>
#include <vector>
#include <sstream>

#include "CommunicationException.h"

#include "StringIntConverter.h"
#include "Serializer.h"
#include "HeadOfficeAdmin.h"
#include "ServerMessenger.h"
#include "Guest.h"
#include "HealthData.h"
#include "Message.h"

using std::string;
using std::vector;

namespace Tom_F
{
	ServerMessenger::ServerMessenger() :
	connection(NULL),
	admin(NULL),
	serializer(Serializer())
	{
	}

	ServerMessenger::ServerMessenger(ConnectionHandler* connection, const HeadOfficeAdmin* admin) :
	connection(connection),
	admin(admin),
	serializer(Serializer())
	{
	}

	ServerMessenger::~ServerMessenger()
	{
	}

	void ServerMessenger::processInput(string input) const
	{
		Message received = serializer.load<Message>(input);
		string command = received.getNextMessage();

		if(command == "ENROL")
		{
			enrolMember(received);
		}
		else if(command == "LOG HEALTH")
		{
			logHealthData(received);
		}
		else if(command == "GET LAST HEALTH")
		{
			getLastHealthLog(received);
		}
		else if(command == "REGISTER")
		{
			registerHealthClub(received);
		}
		else if(command == "HIRE")
		{
			hireEmployee(received);
		}
		else if(command == "LOG MEETING")
		{
			logTrainingMeeting(received);
		}
		else if(command == "GET SIM DATA")
		{
			getSimulationData(received);
		}
		else
		{
			throw Exception::CommunicationException("Command not recognised");
		}
	}

	void ServerMessenger::registerHealthClub(Message& received) const
	{
		Serializer serializer;
		Message toSend;
		int healthClubID = admin->registerHealthClub();

		connection->sendMessage(StringIntConverter::intToString(healthClubID));
	}

	void ServerMessenger::enrolMember(Message& received) const
	{
		Guest member = serializer.load<Guest>(received.getNextMessage());
		int healthClubID = StringIntConverter::stringToInt(received.getNextMessage());

		int membershipID = admin->enrolMember(member, healthClubID);

		connection->sendMessage(StringIntConverter::intToString(membershipID));
	}

	void ServerMessenger::logHealthData(Message& received) const
	{
		HealthData healthData = serializer.load<HealthData>(received.getNextMessage());
		int result = admin->logHealthData(healthData);
		connection->sendMessage(StringIntConverter::intToString(result));
	}

	void ServerMessenger::getLastHealthLog(Message& received) const
	{
		int membershipID = StringIntConverter::stringToInt(received.getNextMessage());
		HealthData lastLog = admin->getLastHealthLog(membershipID);
		connection->sendMessage(serializer.save<HealthData>(lastLog));
	}

	void ServerMessenger::hireEmployee(Message& received) const
	{
		Person toHire = serializer.load<Person>(received.getNextMessage());
		string position = received.getNextMessage();
		int healthClubID = atoi(received.getNextMessage().c_str());

		int result = admin->hireEmployee(toHire, position, healthClubID);

		connection->sendMessage(StringIntConverter::intToString(result));
	}

	void ServerMessenger::logTrainingMeeting(Message& received) const
	{
		TrainingMeeting meeting = serializer.load<TrainingMeeting>(received.getNextMessage());
		int result = admin->logTrainingMeeting(meeting);

		connection->sendMessage(StringIntConverter::intToString(result));
	}

	void ServerMessenger::getSimulationData(Message& received) const
	{

		int healthClubID = StringIntConverter::stringToInt(received.getNextMessage());
		SimulationData data = admin->getSimulationData(healthClubID);

		connection->sendMessage(serializer.save<SimulationData>(data));
	}



} /* namespace Tom_F */
