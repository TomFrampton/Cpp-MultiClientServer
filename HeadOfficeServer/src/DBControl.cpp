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

	DBControl::DBControl()
	{
		// TODO Auto-generated constructor stub

	}

	DBControl::~DBControl()
	{
		// TODO Auto-generated destructor stub
	}

	void DBControl::connect()
	{
		const char* host = "127.0.0.1";
		const char* user = "root";
		const char* pass = "";
		const char* database = "oosd";

		connection = mysql_init(NULL);

		if(!mysql_real_connect(connection, host, user, pass, database, 0, NULL, 0))
		{
			cout << mysql_error(connection) << endl;
		}
	}

	void DBControl::query(string query)
	{
		if(mysql_query(connection, query.c_str()))
		{
			cout << "query worked" << endl;
		}
		else
		{
			cout << mysql_error(connection) << endl;
		}
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

	MYSQL* DBControl::getConnection() const
	{
		return connection;
	}

} /* namespace Tom_F */
