#pragma once
#include "WSSensor.h"
#include "WLSensor.h"
class ISensorFactory
{
public:
	virtual WSSensor* createWSSensor() = 0;
	virtual WLSensor* createWLSensor() = 0;
};