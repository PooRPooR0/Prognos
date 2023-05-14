#pragma once
#include "IGidroStation.h"
#include "Sensors.h"

class GidroStation : public IGidroStation
{
private:
	Sensors* sensors;
public:
	GidroStation();
	GidroStation(Sensors*);
	void collectData() override;
};

