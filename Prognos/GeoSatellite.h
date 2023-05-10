#pragma once
#include "ISatellite.h"
#include <iostream>

class GeoSatellite : public ISatellite
{
public:
	void translate(std::string) override;
	std::string collectData();
};

