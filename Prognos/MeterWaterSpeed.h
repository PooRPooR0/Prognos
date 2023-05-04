#pragma once
#include "IMeterAction.h"
class MeterWaterSpeed : public IMeterAction
{
public:
	int meter() override;
};

