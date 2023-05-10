#include "FormatDecorator.h"

FormatDecorator::FormatDecorator(ISensor* sensor) {
	wrapee = sensor;
}

int FormatDecorator::performMeter() {
	return wrapee->performMeter() * 100;
}