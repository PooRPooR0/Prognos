#include "SlowWLSensor.h"
#include "Windows.h"

int SlowWLSensor::performMeter() {
	Sleep(2000);
	return 0 + rand() % 40;
}