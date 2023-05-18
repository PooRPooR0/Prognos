#pragma once
#include "ISensorFactory.h"
#include "WSSensor.h"
#include "WLSensor.h"
class SlowSensorFactory :
    public ISensorFactory
{
public:
	WSSensor* createWSSensor() override;
	WLSensor* createWLSensor() override;
};

