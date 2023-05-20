#include "DataCalculator.h"
#include <vector>

using namespace std;

DataCalculator::DataCalculator(MementoDataStation* orig) {
	originator = orig;
}

void DataCalculator::calcMax() {
	history.push_back(originator->save());
	originator->calcMax();
}

void DataCalculator::undo() {
	originator->restore(history[history.size() - 1]);
	history.pop_back();
}