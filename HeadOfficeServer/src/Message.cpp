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

	Message::Message() :
	authorIdentifier(-1),
	message("")
	{
		// TODO Auto-generated constructor stub
	}

	Message::Message(int id, const char* message) :
	authorIdentifier(id),
	message(message)
	{

	}

	Message::~Message()
	{
		// TODO Auto-generated destructor stub
	}

	int Message::getAuthorID() const
	{
		return authorIdentifier;
	}

	const char* Message::getMessage() const
	{
		return message;
	}

} /* namespace Tom_F */
