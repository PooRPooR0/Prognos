#include <iostream>
#include "ProxyGidroStation.h"
#include "Antenna.h"
#include "Wire.h"
#include "MeterWaterSpeed.h"
#include "MeterWaterTemperature.h"
#include "MeterWaterLevel.h"
#include "Sensor.h"

using namespace std;

int main()
{
    GidroStation* gs = new GidroStation();

    ProxyGidroStation* proxyGS = new ProxyGidroStation(gs);
    proxyGS->collectData();
    delete proxyGS;
    delete gs;

    Antenna* antena = new Antenna(2);
    antena->performTransmission();
    delete antena;

    Wire* wire = new Wire(5);
    wire->performTransmission();
    delete wire;

    MeterWaterSpeed* mws = new MeterWaterSpeed();
    Sensor* sensor = new Sensor(mws);
    cout << "Water speed: " << sensor->performMeter() << " M/S\n";
    delete sensor;

    MeterWaterTemperature* mwt = new MeterWaterTemperature();
    sensor = new Sensor(mwt);
    cout << "Water temperature: " << sensor->performMeter() << " C\n";
    delete sensor;

    MeterWaterLevel* mwl = new MeterWaterLevel();
    sensor = new Sensor(mwl);
    cout << "Water level: " << sensor->performMeter() << " M\n";
    delete sensor;

    return 0;
}