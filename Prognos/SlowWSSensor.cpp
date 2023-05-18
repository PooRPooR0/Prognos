#include "SlowWSSensor.h"
#include "Windows.h"

int SlowWSSensor::performMeter() {
	Sleep(2000);
	return 2 + rand() % 4;
}