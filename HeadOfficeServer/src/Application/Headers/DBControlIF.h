/*
 * DBControlIF.h
 *
 *  Created on: 5 Mar 2013
 *      Author: Tom
 */

#ifndef DBCONTROLIF_H_
#define DBCONTROLIF_H_

#include <WinSock2.h>
#include <mysql.h>
#include <string>

using std::string;

namespace Tom_F
{
	class DBControlIF
	{
	public:
		DBControlIF();
		virtual ~DBControlIF();

		virtual MYSQL_RES* queryResult(string query) = 0;
		virtual int queryAffectedRows(string query) = 0;
		virtual int queryInsertID(string query) = 0;

		virtual string escapeString(string toEscape) = 0;
	};

} /* namespace Tom_F */

#endif /* DBCONTROLIF_H_ */
