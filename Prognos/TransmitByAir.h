#pragma once
#include "ITransmitAction.h"
class TransmitByAir : public ITransmitAction
{
public:
	void transmit(int) override;
};

