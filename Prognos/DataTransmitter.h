#include "ITransmitAction.h";

#pragma once
class DataTransmitter
{
protected:
	ITransmitAction* transmitAction;
	int transmittionSpeed;
public:
	void performTransmission();
};

