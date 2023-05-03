#include "DataTransmitter.h"

void DataTransmitter::performTransmission() {
	transmitAction->transmit(transmittionSpeed);
}