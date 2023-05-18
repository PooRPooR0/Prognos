#pragma once
#include "WLSensor.h"
class SlowWLSensor :
    public WLSensor
{
public:
    int performMeter() override;
};

