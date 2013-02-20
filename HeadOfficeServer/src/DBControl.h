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
#include <string>

using std::string;

namespace Tom_F
{
	class DBControl
	{
	public:
		DBControl();
		virtual ~DBControl();

		void connect();
		void query(string query);

		string escapeString(string toEscape);

		MYSQL* getConnection() const;


	private:
		MYSQL *connection;
	};

} /* namespace Tom_F */

#endif /* DBCONTROL_H_ */
