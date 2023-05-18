#include "FastWSSensor.h"
#include "Windows.h"

int FastWSSensor::performMeter() {
	Sleep(400);
	return 2 + rand() % 4;
}