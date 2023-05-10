#include "ProxyGidroStation.h"
#include <iostream>
#include <ctime>

ProxyGidroStation::ProxyGidroStation(GidroStation* target) {
	prox = target;
}

bool ProxyGidroStation::checkErrors() {
	return (rand() % 10) > 1;
}

void ProxyGidroStation::collectData() {
	if (checkErrors()) {
		prox->collectData();
	}
	else {
		std::cout << "Error! Collecting not finished\n";
	}
	
}