#pragma once
#include "IGidroStation.h"
#include "GidroStation.h"

class ProxyGidroStation : public IGidroStation
{
private:
	GidroStation* prox;

	bool checkErrors();
public:
	ProxyGidroStation(GidroStation*);

	void collectData() override;
};

