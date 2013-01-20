/*
 * ConnInfo.h
 *
 *  Created on: 12 Jan 2013
 *      Author: Tom
 */

#ifndef CONNINFO_H_
#define CONNINFO_H_

#include "ServerControl.h"

typedef struct ConnInfo{
	ServerControl* server;
	SOCKET* yourSocket;
	pthread_cond_t thisCopyCond;

} ConnInfo;

#endif /* CONNINFO_H_ */
