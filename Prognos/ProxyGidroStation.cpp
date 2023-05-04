#include "ProxyGidroStation.h"
#include <iostream>
#include <ctime>

ProxyGidroStation::ProxyGidroStation() {
	prox = new GidroStation();
}

ProxyGidroStation::~ProxyGidroStation() {
	delete prox;
}

bool ProxyGidroStation::checkErrors() {
	srand(time(0));
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