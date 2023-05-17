#define _CRT_SECURE_NO_WARNINGS
#include "Sensor.h"
#include "Data.h"
#include <string>
#include <ctime>
#include <vector>

using namespace std;

Sensor::Sensor(IMeterAction* nMeterAction, string nName) {
	meterAction = nMeterAction;
	name = nName;
}

Sensor::~Sensor() {
	delete meterAction;
}

Data* Sensor::performMeter() {
	time_t now = time(0);
	tm* gmtm = gmtime(&now);
	return new Data(name + " " + asctime(gmtm), meterAction->meter());
}