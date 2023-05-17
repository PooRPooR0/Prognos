#include "GidroStation.h"
#include <iostream>
#include "Sensors.h"
#include "IIterator.h"
#include "Data.h"
#include <vector>

using namespace std;

GidroStation::GidroStation() {
	sensors = new Sensors();
}

GidroStation::GidroStation(Sensors* s) {
	sensors = s;
}

void GidroStation::collectData() {
    IIterator* iter = sensors->createIterator();
    int num = 0;

    while (iter->hasNext()) {
        num++;
        ISensor* sen = iter->next();
        Data* data = sen->performMeter();

        cout << data->getName() << data->getValue() << "\n";
    }

    if (num == 0) std::cout << "There is no sensors(\n";
    delete iter;
}