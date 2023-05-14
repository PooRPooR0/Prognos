#pragma once
#include "IIterator.h"
#include "Sensors.h"
#include "ISensor.h"
#include <vector>

class SensorsIterator : public IIterator
{
private:
	int iterationState;
	std::vector<ISensor*> collection;
public:
	SensorsIterator(std::vector<ISensor*>);
	bool hasNext() override;
	ISensor* next() override;
};