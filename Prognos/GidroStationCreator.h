#pragma once
#include "IStation.h"
#include "StationCreator.h"
class GidroStationCreator : public StationCreator
{
public:
	IStation* createStation() override;
};

