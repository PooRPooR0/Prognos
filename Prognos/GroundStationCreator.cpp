#include "GroundStationCreator.h"
#include "IStation.h"
#include "GroundStation.h"

IStation* GroundStationCreator::createStation() {
	return new GroundStation();
}