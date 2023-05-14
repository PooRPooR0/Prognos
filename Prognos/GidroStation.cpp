#include "GidroStation.h"
#include <iostream>
#include "Sensors.h"
#include "IIterator.h"

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
        std::cout << sen->performMeter() << "\n";
    }

    if (num == 0) std::cout << "There is no sensors(\n";
    delete iter;
}