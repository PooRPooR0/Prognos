#include "ProxyGidroStation.h"
#include <iostream>

ProxyGidroStation::ProxyGidroStation() {
	prox = new GidroStation();
}

ProxyGidroStation::~ProxyGidroStation() {
	delete prox;
}

void ProxyGidroStation::log() {
	std::cout << "Proxy: Collecting...\n";
}

void ProxyGidroStation::collectData() {
	log();
	prox->collectData();
}