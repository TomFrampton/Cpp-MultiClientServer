/*
 * @file 	 ClientMessenger.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-14
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * Responsible for translating method calls into a Message object and serializing to a char*
 * to be send across the network.
 */

#include <sstream>
#include <cstdlib>

#include "Reception.h"
#include "Person.h"
#include "ClientMessenger.h"
#include "Message.h"
#include "StringIntConverter.h"

namespace Tom_F
{
	/**
	 * Constructor.
	 * @param   connectionControl   The connection object to use to communicate with server
	 */
	ClientMessenger::ClientMessenger(const ClientConnectionControlIF* connectionControl) :
	serializer(Serializer()),
	connectionControl(connectionControl),
	messagingLock(PTHREAD_MUTEX_INITIALIZER) // Mutex to only allow a single server request
	{
	}

	ClientMessenger::~ClientMessenger()
	{
	}

	int ClientMessenger::registerHealthClub()
	{
		Message toSend;
		toSend.addMessage("REGISTER");

		string serializedMessage = serializer.save<Message>(toSend);

		pthread_mutex_lock(&messagingLock);

		connectionControl->sendMessage(serializedMessage);
		int healthClubID = atoi(connectionControl->listenForMessage().c_str());

		pthread_mutex_unlock(&messagingLock);

		return healthClubID;
	}

	int ClientMessenger::hireTrainer(Person& hired, int healthClubID)
	{
		return hireEmployee(hired, "TRAINER", healthClubID);
	}

	int ClientMessenger::enrolMember(const Guest& newMember, int healthClubID)
	{
		Message toSend;
		toSend.addMessage("ENROL");
		toSend.addMessage(serializer.save<Guest>(newMember));
		toSend.addMessage(StringIntConverter::intToString(healthClubID));

		string serializedMessage = serializer.save<Message>(toSend);

		pthread_mutex_lock(&messagingLock);

		connectionControl->sendMessage(serializedMessage);
		int memberID = StringIntConverter::stringToInt(connectionControl->listenForMessage());

		pthread_mutex_unlock(&messagingLock);

		return memberID;
	}

	bool ClientMessenger::logHealthData(const HealthData& data)
	{
		Message toSend;
		toSend.addMessage("LOG HEALTH");
		toSend.addMessage(serializer.save<HealthData>(data));

		string serializedMessage = serializer.save<Message>(toSend);

		pthread_mutex_lock(&messagingLock);

		connectionControl->sendMessage(serializedMessage);
		int result = StringIntConverter::stringToInt(connectionControl->listenForMessage());

		pthread_mutex_unlock(&messagingLock);

		return result > 0;
	}

	HealthData ClientMessenger::getLastHealthLog(int membershipID)
	{
		Message toSend;
		toSend.addMessage("GET LAST HEALTH");
		toSend.addMessage(StringIntConverter::intToString(membershipID));

		string serializedMessage = serializer.save<Message>(toSend);

		pthread_mutex_lock(&messagingLock);

		connectionControl->sendMessage(serializedMessage);
		string serializedData = connectionControl->listenForMessage();

		pthread_mutex_unlock(&messagingLock);

		return serializer.load<HealthData>(serializedData);
	}

	int ClientMessenger::hireEmployee(Person& hired, string position, int healthClubID)
	{
		Message toSend;
		toSend.addMessage("HIRE");
		toSend.addMessage(serializer.save(hired));
		toSend.addMessage(position);
		toSend.addMessage(StringIntConverter::intToString(healthClubID));

		string serializedMessage = serializer.save<Message>(toSend);

		pthread_mutex_lock(&messagingLock);

		connectionControl->sendMessage(serializedMessage);
		int employeeID = StringIntConverter::stringToInt(connectionControl->listenForMessage());

		pthread_mutex_unlock(&messagingLock);

		return employeeID;
	}

	bool ClientMessenger::logTrainingMeeting(const TrainingMeeting& meeting)
	{
		Message toSend;
		toSend.addMessage("LOG MEETING");
		toSend.addMessage(serializer.save(meeting));

		string serializedMessage = serializer.save<Message>(toSend);

		pthread_mutex_lock(&messagingLock);

		connectionControl->sendMessage(serializedMessage);
		int result = StringIntConverter::stringToInt(connectionControl->listenForMessage());

		pthread_mutex_unlock(&messagingLock);

		return result > 0;
	}

	SimulationData ClientMessenger::getSimulationData(int healthClubID)
	{
		Message toSend;
		toSend.addMessage("GET SIM DATA");
		toSend.addMessage(StringIntConverter::intToString(healthClubID));

		string serializedMessage = serializer.save<Message>(toSend);

		pthread_mutex_lock(&messagingLock);

		connectionControl->sendMessage(serializedMessage);
		string serializedData = connectionControl->listenForMessage();

		pthread_mutex_unlock(&messagingLock);

		return serializer.load<SimulationData>(serializedData);
	}

} /* namespace Tom_F */
