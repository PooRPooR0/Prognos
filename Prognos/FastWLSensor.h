#pragma once
#include "WLSensor.h"
class FastWLSensor :
    public WLSensor
{
public:
    int performMeter() override;
};

