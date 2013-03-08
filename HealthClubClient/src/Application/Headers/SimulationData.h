/*
 * SimulationData.h
 *
 *  Created on: 1 Mar 2013
 *      Author: Tom
 */

#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_

#include <boost/serialization/access.hpp>
#include <vector>

using std:: vector;

namespace Tom_F
{
	class SimulationData {
	public:
		SimulationData();
		SimulationData(const SimulationData& toCopy);
		SimulationData(int enrolledCount, int averageWaitingTime);
		virtual ~SimulationData();

		int getEnrolledCount() const;
		int getAverageWaitingTime() const;

	private:
		int enrolledCount;
		double averageWaitingTime;


		friend class boost::serialization::access;
		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int version)
		{
			ar & enrolledCount;
			ar & averageWaitingTime;
		}
	};

} /* namespace Tom_F */
#endif /* SIMULATIONDATA_H_ */
