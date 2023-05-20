#pragma once
#include "IVision.h"
#include <string>
class StateGeoSatellite
{
private:
	IVision* visionState;
public:
	StateGeoSatellite(IVision*);
	void changeState(IVision*);
	std::string collectData();
};

