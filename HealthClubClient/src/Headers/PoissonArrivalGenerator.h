/*
 * PoissonArrivalGenerator.h
 *
 *  Created on: 24 Feb 2013
 *      Author: Tom
 */

#ifndef POISSONARRIVALGENERATOR_H_
#define POISSONARRIVALGENERATOR_H_

namespace Tom_F {

class PoissonArrivalGenerator {
public:
	PoissonArrivalGenerator();
	PoissonArrivalGenerator(int arrivalSlots, int averageInterval);
	virtual ~PoissonArrivalGenerator();

	bool hasArrived();

	int getArrivalSlotsSize() const;

private:
	bool* arrivalSlots;
	const int arrivalSlotsSize;
	int nextArrivalSlot;

	void generateArrivals(int arrivalSlots, int averageInterval);

};

} /* namespace Tom_F */
#endif /* POISSONARRIVALGENERATOR_H_ */
