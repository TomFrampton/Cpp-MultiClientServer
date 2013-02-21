/*
 * @file 	 ClientMessenger.cpp
 * @author	 Tom Frampton
 * @date 	 2013-02-14
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Serializer.h"
#include "Reception.h"

#include "ClientMessenger.h"
#include "Message.h"

using namespace std;


namespace Tom_F
{
	ClientMessenger::ClientMessenger(const ClientConnectionControl& connectionControl) :
	// Initialise const data member
	connectionControl(connectionControl)
	{

	}

	ClientMessenger::~ClientMessenger()
	{
		// TODO Auto-generated destructor stub
	}

	void ClientMessenger::listenForClientInput()
	{
		cout << "Type your message and press enter to send to server" << endl;

		for(;;Sleep(10))
		{
			/*string inputString;
			getline(cin, inputString);
			const char* input = inputString.c_str();
			connectionControl.sendMessage(input);*/
		}
	}

	void ClientMessenger::enrolMember(Guest& newMember) const
	{
		Serializer serializer;
		string ser = serializer.save<Guest>(newMember);

		connectionControl.sendMessage("ENROL");
		connectionControl.sendMessage(serializer.save(newMember));

		cout << connectionControl.listenForMessage() << endl;
	}

} /* namespace Tom_F */
