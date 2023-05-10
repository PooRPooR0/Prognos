#pragma once
#include "ISensor.h"
class SensorDecorator : public ISensor
{
protected:
	ISensor* wrapee;
public:
	virtual int performMeter() = 0;
};

