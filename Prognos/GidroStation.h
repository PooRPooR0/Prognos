#pragma once
#include "IGidroStation.h"

class GidroStation : public IGidroStation
{
public:
	void collectData() override;
};

