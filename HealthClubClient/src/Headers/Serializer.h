/*
 * Serializer.h
 *
 *  Created on: 21 Feb 2013
 *      Author: Tom
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <string>
#include <sstream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using std::string;
using std::stringstream;

namespace Tom_F
{
	class Serializer
	{
	public:
		Serializer();
		virtual ~Serializer();

		template <typename Serializable>
		string save(Serializable object)
		{
			object.getForename();
			stringstream ss;
			boost::archive::text_oarchive oa(ss);
			oa << object;
			return ss.str();
		}

		template <typename Serializable>
		Serializable load(string serializedObject)
		{
			stringstream ss;
			ss << serializedObject;
			boost::archive::text_iarchive ia(ss);
			Serializable object;
			ia >> object;
			return object;
		}
	};

} /* namespace Tom_F */
#endif /* SERIALIZER_H_ */
