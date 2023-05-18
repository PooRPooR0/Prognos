#include "GroundStation.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> GroundStation::collectData() {
	cout << "Collecting from ground...\n";
	return vector<int>(4, 100);
}