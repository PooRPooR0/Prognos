#pragma once
#include "ISensorFactory.h"
#include "WSSensor.h"
#include "WLSensor.h"
class FastSensorFactory :
    public ISensorFactory
{
public:
	WSSensor* createWSSensor() override;
	WLSensor* createWLSensor() override;
};

