#include "Wire.h"
#include "TransmitByWire.h"

Wire::Wire() {
	transmitAction = new TransmitByWire();
	transmittionSpeed = 0;
}

Wire::Wire(int speed) {
	transmitAction = new TransmitByWire();
	transmittionSpeed = speed;
}

Wire::~Wire() {
	delete transmitAction;
}
