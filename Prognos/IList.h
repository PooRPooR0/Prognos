#pragma once
#include "IIterator.h"

class IList
{
public:
	virtual IIterator* createIterator() = 0;
};

