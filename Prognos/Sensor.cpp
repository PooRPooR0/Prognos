#include "Sensor.h"

Sensor::Sensor(IMeterAction* nMeterAction) {
	meterAction = nMeterAction;
}

Sensor::~Sensor() {
	delete meterAction;
}

int Sensor::performMeter() {
	return meterAction->meter();
}