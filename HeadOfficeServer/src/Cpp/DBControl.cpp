/*
 * DBControl.cpp
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#include <iostream>

#include "DBControl.h"

using namespace std;

namespace Tom_F
{

	DBControl::DBControl() :
	connection(mysql_init(NULL)),
	queryLock(PTHREAD_MUTEX_INITIALIZER)
	{
		connect();
	}

	DBControl::~DBControl()
	{
		close();
	}

	void DBControl::connect()
	{
		const char* host = "127.0.0.1";
		const char* user = "root";
		const char* pass = "";
		const char* database = "oosd";

		if(!mysql_real_connect(connection, host, user, pass, database, 0, NULL, 0))
		{
			cout << mysql_error(connection) << endl;
		}
	}

	MYSQL_RES* DBControl::query(string query)
	{
		MYSQL_RES* result = NULL;
		pthread_mutex_lock(&queryLock);
		if(mysql_query(connection, query.c_str()))
		{
			cout << mysql_error(connection) << endl;
			result = NULL;
		}
		else
		{
			result = mysql_store_result(connection);
		}
		pthread_mutex_unlock(&queryLock);
		return result;
	}

	int DBControl::queryAffectedRows(string query)
	{
		int result = 0;
		pthread_mutex_lock(&queryLock);
		if(mysql_query(connection, query.c_str()))
		{
			cout << mysql_error(connection) << endl;
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
			cout << mysql_error(connection) << endl;
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
