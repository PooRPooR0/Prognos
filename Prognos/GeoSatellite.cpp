#include "GeoSatellite.h"
#include <iostream>
#include <ctime>
#include <string> 

void GeoSatellite::translate(std::string data) {
	std::cout << "Transmitting \"" << data << "\"...\n";
}

std::string GeoSatellite::collectData() {
	srand(time(0));

	std::string data = "";

	for (int i = 0; i < 20; i++) {
		data.append(std::to_string(rand() % 10));
	}

	return data;
}