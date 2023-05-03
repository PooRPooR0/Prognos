#include "Antenna.h"
#include "TransmitByAir.h"

Antenna::Antenna() {
	transmitAction = new TransmitByAir();
	transmittionSpeed = 0;
}

Antenna::Antenna(int speed) {
	transmitAction = new TransmitByAir();
	transmittionSpeed = speed;
}

Antenna::~Antenna() {
	delete transmitAction;
}
