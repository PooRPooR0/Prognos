#pragma once
#include "ISatellite.h"
#include "RetranslatorSatellite.h"

class SatelliteAdapter : public ISatellite
{
private:
	RetranslatorSatellite* adaptee;
public:
	SatelliteAdapter(RetranslatorSatellite*);
	void translate(std::string) override;
};

