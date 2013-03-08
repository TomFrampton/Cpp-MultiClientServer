/*
 * @file 	 Message.h
 * @author	 Tom Frampton
 * @date 	 *************************
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <boost/serialization/deque.hpp>
#include <string>
#include <deque>

using std::string;
using std::deque;

namespace Tom_F
{

	class Message
	{
		public:
			Message();
			virtual ~Message();

			void addMessage(string message);
			string getNextMessage();

		private:
			deque<string> messages;

			friend class boost::serialization::access;

			template<typename Archive>
			void serialize(Archive& ar, const unsigned int version)
			{
				ar & messages;
			}

		};

} /* namespace Tom_F */
#endif /* MESSAGE_H_ */
