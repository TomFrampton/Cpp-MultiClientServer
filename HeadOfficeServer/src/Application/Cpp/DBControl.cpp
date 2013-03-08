/*
 * DBControl.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include <Winsock2.h>

#include "DatabaseException.h"

#include "DBControl.h"

namespace Tom_F
{
	/**
	 * Constructor. Connects to the database and intializes the mutex for
	 * querying the database.
	 */
	DBControl::DBControl() :
	connection(mysql_init(NULL)),
	queryLock(PTHREAD_MUTEX_INITIALIZER)
	{
		connect(); // Connect to database
	}

	/**
	 * Destructor. Close the database connection.
	 */
	DBControl::~DBControl()
	{
		close();
	}

	/**
	 * Connect to the database using the connection details specified.
	 */
	void DBControl::connect()
	{
		const char* host = "127.0.0.1"; // IP of the database server
		const char* user = "root"; // Database login
		const char* pass = ""; // Database password
		const char* database = "oosd"; // Database to use

		// Connect to the database and check for errors
		if(!mysql_real_connect(connection, host, user, pass, database, 0, NULL, 0))
		{
			throw Exception::DatabaseException("Error connecting to database");
		}
	}

	/**
	 * Query the database and return the rows selected. Note returning a pointer
	 * is not a mistake.
	 * @param   query       The SQL query to run
	 * @return  MYSQL_RES*  A pointer to the rows returned by the query
	 */
	MYSQL_RES* DBControl::queryResult(string query)
	{
		MYSQL_RES* result = NULL;
		// Lock the object. Only want a single query running at once
		pthread_mutex_lock(&queryLock);
		// Query the database and check for success
		if(mysql_query(connection, query.c_str()))
		{
			result = NULL; // No success
		}
		else
		{
			// Success - get the rows returned by the query
			result = mysql_store_result(connection);
		}
		pthread_mutex_unlock(&queryLock); // Unlock the object
		return result; // Return the query rows
	}

	int DBControl::queryAffectedRows(string query)
	{
		int result = 0;
		pthread_mutex_lock(&queryLock);
		if(mysql_query(connection, query.c_str()))
		{
			result = 0;
		}
		else
		{
			result = mysql_affected_rows(connection);
		}
		pthread_mutex_unlock(&queryLock);
		return result;
	}

	int DBControl::queryInsertID(string query)
	{
		int result = 0;
		pthread_mutex_lock(&queryLock);
		if(mysql_query(connection, query.c_str()))
		{
			result = 0;
		}
		else
		{
			result = mysql_insert_id(connection);
		}
		pthread_mutex_unlock(&queryLock);
		return result;
	}

	void DBControl::close()
	{
		mysql_close(connection);
	}

	string DBControl::escapeString(string toEscape)
	{
		const char* from = toEscape.c_str();
		char* to = new char[strlen(from) * 2 + 1];
		mysql_real_escape_string(connection, to, from, strlen(from));
		string escaped(to);
		delete[] to;
		return escaped;
	}

} /* namespace Tom_F */
