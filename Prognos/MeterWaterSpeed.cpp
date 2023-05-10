#include "MeterWaterSpeed.h"
#include <iostream>
#include <ctime>

int MeterWaterSpeed::meter() {
	return 2 + rand() % 4;
}