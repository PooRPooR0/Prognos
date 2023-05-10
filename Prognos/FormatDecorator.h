#pragma once
#include "SensorDecorator.h"
#include "ISensor.h"
class FormatDecorator : public SensorDecorator
{
public:
	FormatDecorator(ISensor*);
	int performMeter() override;
};