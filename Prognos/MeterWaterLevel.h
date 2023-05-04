#pragma once
#include "IMeterAction.h"
class MeterWaterLevel : public IMeterAction
{
public:
	int meter() override;
};

