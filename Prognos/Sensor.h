#pragma once
#include "IMeterAction.h"

class Sensor
{
private:
	IMeterAction* meterAction;
public:
	Sensor(IMeterAction*);
	~Sensor();

	int performMeter();
};

