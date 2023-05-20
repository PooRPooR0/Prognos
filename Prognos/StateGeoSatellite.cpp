#include "StateGeoSatellite.h"
#include "IVision.h"
#include <string>

using namespace std;

StateGeoSatellite::StateGeoSatellite(IVision* vision) {
	visionState = vision;
}

void StateGeoSatellite::changeState(IVision* vision) {
	visionState = vision;
}

std::string StateGeoSatellite::collectData() {
	return visionState->collectData();
}