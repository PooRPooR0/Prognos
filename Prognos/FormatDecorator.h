#pragma once
#include "SensorDecorator.h"
#include "ISensor.h"
#include "Data.h"
class FormatDecorator : public SensorDecorator
{
public:
	FormatDecorator(ISensor*);
	Data* performMeter() override;
};