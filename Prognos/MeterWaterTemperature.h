#pragma once
#include "IMeterAction.h"
class MeterWaterTemperature : public IMeterAction
{
public:
	int meter() override;
};

