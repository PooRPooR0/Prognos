#pragma once
#include "Data.h"
class ISensor
{
public:
	virtual Data* performMeter() = 0;
};

