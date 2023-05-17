#pragma once
#include "IMeterAction.h"
#include "ISensor.h"
#include "Data.h"
#include <string>

class Sensor : public ISensor
{
private:
	IMeterAction* meterAction;
	std::string name;
public:
	Sensor(IMeterAction*, std::string);
	~Sensor();

	Data* performMeter() override;
};

