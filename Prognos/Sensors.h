#pragma once
#include "IList.h"
#include "ISensor.h"
#include <vector>

class Sensors : public IList
{
private:
	std::vector<ISensor*> sensors;
public:
	void addSensor(ISensor*);
	void removeSensor(ISensor*);
	IIterator* createIterator() override;
};

