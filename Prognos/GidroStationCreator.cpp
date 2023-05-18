#include "GidroStationCreator.h"
#include "IStation.h"
#include "FMGidroStation.h"

IStation* GidroStationCreator::createStation() {
	return new FMGidroStation();
}