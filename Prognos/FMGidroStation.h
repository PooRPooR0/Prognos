#pragma once
#include <vector>
#include "IStation.h"
class FMGidroStation : public IStation
{
public:
	std::vector<int> collectData() override;
};

