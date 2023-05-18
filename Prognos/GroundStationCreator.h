#pragma once
#include "StationCreator.h"
#include "IStation.h"
class GroundStationCreator : public StationCreator
{
public:
	IStation* createStation() override;
};

