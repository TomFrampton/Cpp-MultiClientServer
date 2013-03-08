/*
 * @file 	 ConnectionException.cpp
 * @author	 Tom Frampton
 * @date 	 2013-03-06
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This exception is thrown when there is an error setting up the server's
 * connection. For example, a bind or listening error.
 */

#include "ConnectionException.h"

namespace Tom_F
{
	namespace Exception
	{
		/**
		 * Default constructor. Initialize a default explantion message
		 */
		ConnectionException::ConnectionException() throw ():
		explanation("Connection failure")
		{
		}

		/**
		 * Constructor. Initialize the exception with a custom explanation message
		 * @param   explanation   The explanation message to use
		 */
		ConnectionException::ConnectionException(string explanation) throw() :
		explanation(explanation)
		{
		}

		/**
		 * Destructor
		 */
		ConnectionException::~ConnectionException() throw()
		{
		}

		/**
		 * Get the explanation for this exception
		 * @return   string   The explanation message
		 */
		string ConnectionException::getExplanation() const
		{
			return explanation;
		}

	} /* namespace Exception */

} /* namespace Tom_F */
