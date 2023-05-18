#include "FastWLSensor.h"
#include "Windows.h"

int FastWLSensor::performMeter() {
	Sleep(400);
	return 0 + rand() % 40;
}