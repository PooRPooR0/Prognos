#pragma once
#include "IMeterAction.h"
#include "ISensor.h"

class Sensor : public ISensor
{
private:
	IMeterAction* meterAction;
public:
	Sensor(IMeterAction*);
	~Sensor();

	int performMeter() override;
};

