/*
 * TrainingMeeting.h
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#ifndef TRAININGMEETING_H_
#define TRAININGMEETING_H_

#include <string>
#include <boost/serialization/access.hpp>

using std::string;

namespace Tom_F
{
	class TrainingMeeting
	{
	public:
		TrainingMeeting();
		TrainingMeeting(const TrainingMeeting& toCopy);
		TrainingMeeting(int membershipID, int employeeID, int waitingTime, string meetingType);
		virtual ~TrainingMeeting();

		void setMeetingType(string meetingType);

		int getMembershipID() const;
		int getEmployeeID() const;
		int getWaitingTime() const;
		string getMeetingType() const;

	private:
		int membershipID;
		int employeeID;
		int waitingTime;
		string meetingType;

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar & membershipID;
			ar & employeeID;
			ar & waitingTime;
			ar & meetingType;
		}
	};

} /* namespace Tom_F */
#endif /* TRAININGMEETING_H_ */
