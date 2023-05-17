#include "MultiSensor.h"
#include "ISensor.h"
#include <vector>
#include "Data.h"

using namespace std;

Data* MultiSensor::performMeter() {
	Data* data = new Data("", -1);

	for (auto child = begin(children); child != end(children); child++) {
		Data* val = (*child)->performMeter();
		data->addChild(val);
	}

	return data;
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