#include "MeterWaterLevel.h"
#include <iostream>
#include <ctime>

int MeterWaterLevel::meter() {
	srand(time(0));
	return 0 + rand() % 40;
}