#include "SensorsIterator.h"
#include <vector>

SensorsIterator::SensorsIterator(std::vector<ISensor*> sensors) {
	collection = sensors;
	iterationState = 0;
}

bool SensorsIterator::hasNext() {
	return iterationState < collection.size();
}

ISensor* SensorsIterator::next() {
	iterationState++;
	return collection[iterationState - 1];
}