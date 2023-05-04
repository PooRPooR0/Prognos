#pragma once
#include "ITransmitAction.h"
class TransmitByWire : public ITransmitAction
{
public:
	void transmit(int) override;
};

