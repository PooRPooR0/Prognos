#include "MeterWaterTemperature.h"
#include <iostream>
#include <ctime>

int MeterWaterTemperature::meter() {
	srand(time(0));
	return 3 + rand() % 16;
}