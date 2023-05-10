#include "MultiSensor.h"
#include "ISensor.h"
#include <vector> 

using namespace std;

int MultiSensor::performMeter() {
	int max = 0;

	for (auto child = begin(children); child != end(children); child++) {
		int val = (*child)->performMeter();
		if (max < val) max = val;
	}

	return max;
}

void MultiSensor::add(ISensor* sensor) {
	children.push_back(sensor);
}

void MultiSensor::remove(ISensor* sensor) {
	for (auto child = begin(children); child != end(children); child++) {
		if (*child == sensor) {
			children.erase(child);
			break;
		}
	}
}

vector<ISensor*> MultiSensor::getChildren() {
	return children;
}