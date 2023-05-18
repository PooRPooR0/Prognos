#pragma once
#include "WSSensor.h"
class FastWSSensor :
    public WSSensor
{
public:
    int performMeter() override;
};

