#pragma once
#include "MementoDataStation.h"
#include <vector>
class DataCalculator
{
private:
	MementoDataStation* originator;
	std::vector<MementoDataStation::Snapshot*> history;
public:
	DataCalculator(MementoDataStation*);
	void calcMax();
	void undo();
};

