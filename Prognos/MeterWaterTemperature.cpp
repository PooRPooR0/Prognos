#include "MeterWaterTemperature.h"
#include <iostream>
#include <ctime>

int MeterWaterTemperature::meter() {
	return 3 + rand() % 16;
}