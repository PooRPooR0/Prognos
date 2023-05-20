#pragma once
#include <vector>
class MementoDataStation
{
private:
	std::vector<int> data;
public:
	class Snapshot {
	private:
		std::vector<int> data;
	public:
		Snapshot(std::vector<int>);
		std::vector<int> getState();
	};

	Snapshot* save();
	void restore(Snapshot*);
	void pushValue(int);
	std::vector<int> getValues();
	void calcMax();
};

