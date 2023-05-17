#pragma once
#include <string>
#include <vector>

class Data
{
private:
	std::string name;
	int value;
	std::vector<Data*> childrens;
public:
	Data(std::string, int);
	std::string getName();
	int getValue();
	void addChild(Data*);
	std::vector<Data*> getChildrens();
	static void printTree(Data*, int);
};

