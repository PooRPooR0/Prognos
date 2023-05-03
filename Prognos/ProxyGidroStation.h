#pragma once
#include "IGidroStation.h"
#include "GidroStation.h"

class ProxyGidroStation : public IGidroStation
{
private:
	GidroStation* prox;

	void log();
public:
	ProxyGidroStation();
	~ProxyGidroStation();

	void collectData() override;
};

