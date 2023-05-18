#include "FMGidroStation.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> FMGidroStation::collectData() {
	cout << "Collecting from water...\n";
	return vector<int>(4, 100);
}