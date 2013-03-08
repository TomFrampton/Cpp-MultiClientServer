/*
 * @file 	 Message.cpp
 * @author	 Tom Frampton
 * @date 	 ***************************
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#include "Message.h"

namespace Tom_F
{
	Message::Message()
	{
		// TODO Auto-generated constructor stub
	}

	Message::~Message()
	{
		// TODO Auto-generated destructor stub
	}

	string Message::getNextMessage()
	{
		if(messages.size() == 0)
		{
			return "";
		}
		else
		{
			string nextMessage = messages.front();
			messages.pop_front();
			return nextMessage;
		}
	}

	void Message::addMessage(string message)
	{
		messages.push_back(message);
	}

} /* namespace Tom_F */
