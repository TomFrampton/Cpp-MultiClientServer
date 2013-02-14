/*
 * @file 	 ServerConnectionControl.h
 * @author	 Tom Frampton
 * @date 	 2013-02-14
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This class is reponsible for identifying char* messages passed over the network, unserializing any objects,
 * and calling the appropriate methods on the server side.
 */

#ifndef SERVERMESSENGER_H_
#define SERVERMESSENGER_H_

namespace Tom_F
{
	class ServerMessenger
	{
	public:
		ServerMessenger();
		virtual ~ServerMessenger();
	};

} /* namespace Tom_F */

#endif /* SERVERMESSENGER_H_ */
