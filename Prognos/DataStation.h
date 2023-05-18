#pragma once
#include <vector>
class DataStation
{
private:
	static DataStation* instance;
	std::vector<int> data;
	DataStation() {}
public:
	DataStation(DataStation& other) = delete;
	static DataStation* getInstance();
	void pushValue(int);
	std::vector<int> getValues();
};

