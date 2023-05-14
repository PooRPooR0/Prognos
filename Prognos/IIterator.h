#pragma once
#include "ISensor.h"

class IIterator
{
public:
	virtual bool hasNext() = 0;
	virtual ISensor* next() = 0;
};