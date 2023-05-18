#pragma once
#include "IStation.h"
class StationCreator
{
public:
	virtual IStation* createStation() = 0;
};