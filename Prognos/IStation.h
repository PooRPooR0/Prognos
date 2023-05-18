#pragma once
#include <vector>
class IStation
{
public:
	virtual std::vector<int> collectData() = 0;
};

