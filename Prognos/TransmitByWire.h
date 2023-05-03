#pragma once
#include "ITransmitAction.h"
class TransmitByWire : public ITransmitAction
{
public:
	virtual void transmit(int) override;
};

