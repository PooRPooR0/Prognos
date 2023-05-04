#include "MeterWaterSpeed.h"
#include <iostream>
#include <ctime>

int MeterWaterSpeed::meter() {
	srand(time(0));
	return 2 + rand() % 4;
}