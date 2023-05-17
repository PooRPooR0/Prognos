#pragma once
#include "ISensor.h"
#include <vector>
#include "Data.h"

class MultiSensor : public ISensor
{
private:
	std::vector<ISensor*> children;
public:
	Data* performMeter() override;
	void add(ISensor*);
	void remove(ISensor*);
	std::vector<ISensor*> getChildren();
};

