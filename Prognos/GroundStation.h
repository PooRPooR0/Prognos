#pragma once
#include <vector>
#include "IStation.h"
class GroundStation : public IStation
{
public:
	std::vector<int> collectData() override;
};