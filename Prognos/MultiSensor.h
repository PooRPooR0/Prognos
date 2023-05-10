#pragma once
#include "ISensor.h"
#include <vector>

class MultiSensor : public ISensor
{
private:
	std::vector<ISensor*> children;
public:
	int performMeter() override;
	void add(ISensor*);
	void remove(ISensor*);
	std::vector<ISensor*> getChildren();
};

