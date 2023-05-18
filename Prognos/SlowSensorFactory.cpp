#include "SlowSensorFactory.h"
#include "WSSensor.h"
#include "WLSensor.h"
#include "SlowWSSensor.h"
#include "SlowWLSensor.h"

WSSensor* SlowSensorFactory::createWSSensor() {
	return new SlowWSSensor();
}

WLSensor* SlowSensorFactory::createWLSensor() {
	return new SlowWLSensor();
}