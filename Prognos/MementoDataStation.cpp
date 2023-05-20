#include "MementoDataStation.h"
#include <vector>

using namespace std;

MementoDataStation::Snapshot::Snapshot(vector<int> d) {
	data = d;
}

vector<int> MementoDataStation::Snapshot::getState() {
	return data;
}

MementoDataStation::Snapshot* MementoDataStation::save() {
	return new Snapshot(data);
}

void MementoDataStation::restore(Snapshot* s) {
	data = s->getState();
}

void MementoDataStation::pushValue(int v) {
	data.push_back(v);
}

vector<int> MementoDataStation::getValues() {
	return data;
}

void MementoDataStation::calcMax() {
	int max = data[0];
	for (int i = 0; i < data.size(); i++) {
		if (max < data[i]) max = data[i];
	}
	data.clear();
	data.push_back(max);
}