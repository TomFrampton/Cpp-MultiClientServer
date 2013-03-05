/*
 * DBControl.h
 *
 *  Created on: 20 Feb 2013
 *      Author: Tom
 */

#ifndef DBCONTROL_H_
#define DBCONTROL_H_

#include <Winsock2.h>
#include <mysql.h>
#include <pthread.h>
#include <string>

using std::string;

namespace Tom_F
{
	class DBControl
	{
	public:
		DBControl();
		virtual ~DBControl();

		MYSQL_RES* query(string query);
		int queryAffectedRows(string query);
		int queryInsertID(string query);

		string escapeString(string toEscape);

	private:
		MYSQL *connection;
		pthread_mutex_t queryLock;
		void connect();
		void close();
	};

} /* namespace Tom_F */

#endif /* DBCONTROL_H_ */
