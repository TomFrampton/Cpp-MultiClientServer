/*
 * @file 	 Serializer.h
 * @author	 Tom Frampton
 * @date 	 2013-02-21
 * @version  1.0
 * Copyright 2013 Tom Frampton
 */

/**
 * This class is responsible for saving and loading serializable objects.
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

		/**
		 * Saves a serializable object (i.e. Any object that has implemented boost::serializable functionality)
		 * and returns the output stream as a string
		 * @param    object   The object to be serialized
		 * @return   string   The object in serialized form
		 */
		template <typename Serializable>
		string save(Serializable object) const
		{
			stringstream ss; // The stream that the object will be serialized into
			boost::archive::text_oarchive oa(ss); // Set the stringstream as the output archive to be used
			oa << object; // Serialize
			return ss.str(); // Return the stringstream as a string
		}

		/**
		 * Loads an object (i.e. Any object that has implemented boost::serializable functionality) from a
		 * string of the object in serialized form and returns the object.
		 * @param    serializedObject   The object in serialized form to be loaded
		 * @return   Serializable       A template type for the object that was deserialized
		 */
		template <typename Serializable>
		Serializable load(string serializedObject) const
		{
			stringstream ss; // The stringstream that the object will be loaded from
			ss << serializedObject; // Push serialized object into the stream
			boost::archive::text_iarchive ia(ss); // Set the stringstream as the input archive
			Serializable object; // The object that will be loaded
			ia >> object; // Deserialize
			return object; // Return the object
		}
	};

} /* namespace Tom_F */

#endif /* SERIALIZER_H_ */
