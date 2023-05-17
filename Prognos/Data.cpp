#include "Data.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Data::Data(string nName, int nValue) {
	name = nName;
	value = nValue;
}

string Data::getName() {
	return name;
}

int Data::getValue() {
	return value;
}

void Data::addChild(Data* child) {
	childrens.push_back(child);
}

vector<Data*> Data::getChildrens() {
	return childrens;
}

void Data::printTree(Data* node, int level) {
	for (int i = 1; i < level; i++) {
		cout << "\t";
	}
	cout << node->getValue() << "\n";
	vector<Data*> ch = node->getChildrens();
	for (int i = 0; i < ch.size(); i++) {
		Data::printTree(ch[i], level + 1);
	}
}