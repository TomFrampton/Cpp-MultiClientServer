/*
 * @file 	 Message.h
 * @author	 Tom Frampton
 * @date 	 *************************
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

namespace Tom_F
{

class Message
{
	public:
		Message();
		Message(int id, const char* message);
		virtual ~Message();

		int getAuthorID() const;
		const char* getMessage() const;

	private:
		const int authorIdentifier;
		const char* const message;
	};

} /* namespace Tom_F */
#endif /* MESSAGE_H_ */
