#include "FastSensorFactory.h"
#include "WSSensor.h"
#include "WLSensor.h"
#include "FastWSSensor.h"
#include "FastWLSensor.h"

WSSensor* FastSensorFactory::createWSSensor() {
	return new FastWSSensor();
}

WLSensor* FastSensorFactory::createWLSensor() {
	return new FastWLSensor();
}