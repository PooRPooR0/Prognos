#pragma once
#include "WSSensor.h"
class SlowWSSensor :
    public WSSensor
{
public:
    int performMeter() override;
};

