#include "SatelliteAdapter.h"
#include "RetranslatorSatellite.h"

SatelliteAdapter::SatelliteAdapter(RetranslatorSatellite* satelliteToAdapt) {
	adaptee = satelliteToAdapt;
}

void SatelliteAdapter::translate(std::string data) {
	adaptee->uniqTranslate(data);
}