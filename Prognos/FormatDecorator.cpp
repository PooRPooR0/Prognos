#include "FormatDecorator.h"
#include "Windows.h"
#include "Data.h"
#include <vector>
#include <string>

using namespace std;

FormatDecorator::FormatDecorator(ISensor* sensor) {
	wrapee = sensor;
}

Data* FormatDecorator::performMeter() {
	Data* f = wrapee->performMeter();
	int diff = f->getValue();
	string name = f->getName();

	Sleep(4000);
	diff = wrapee->performMeter()->getValue() - diff;

	return new Data(name, diff);
}