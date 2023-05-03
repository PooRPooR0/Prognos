#pragma once
#include "DataTransmitter.h"
class Wire : public DataTransmitter {
public:
	Wire();
	Wire(int);
	~Wire();
};

