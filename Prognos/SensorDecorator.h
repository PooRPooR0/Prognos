#pragma once
#include "ISensor.h"
#include "Data.h"
class SensorDecorator : public ISensor
{
protected:
	ISensor* wrapee;
public:
	virtual Data* performMeter() = 0;
};

