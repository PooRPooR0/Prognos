#pragma once
#include <iostream>

class ISatellite
{
public:
	virtual void translate(std::string) = 0;
};

