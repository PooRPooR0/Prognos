#include "Sensors.h"
#include "IIterator.h"
#include "SensorsIterator.h"
#include <vector>

using namespace std;

IIterator* Sensors::createIterator() {
	return new SensorsIterator(sensors);
}

void Sensors::addSensor(ISensor* sensor) {
	sensors.push_back(sensor);
}

void Sensors::removeSensor(ISensor* sensor) {
	for (auto child = begin(sensors); child != end(sensors); child++) {
		if (*child == sensor) {
			sensors.erase(child);
			break;
		}
	}
}