#include "DataStation.h"
#include <vector>

using namespace std;

DataStation* DataStation::instance;

DataStation* DataStation::getInstance() {
	if (instance == nullptr) {
		instance = new DataStation();
	}
	return instance;
}

void DataStation::pushValue(int val) {
	data.push_back(val);
}

vector<int> DataStation::getValues() {
	return data;
}