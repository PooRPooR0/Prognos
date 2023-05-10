#include <iostream>
#include "ProxyGidroStation.h"
#include "Antenna.h"
#include "Wire.h"
#include "MeterWaterSpeed.h"
#include "MeterWaterTemperature.h"
#include "MeterWaterLevel.h"
#include "Sensor.h"
#include "GeoSatellite.h"
#include "RetranslatorSatellite.h"
#include "SatelliteAdapter.h"
#include "MultiSensor.h"

using namespace std;

void lab4() {
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
}

void adapter() {
    GeoSatellite* gs = new GeoSatellite();
    string data = gs->collectData();
    gs->translate(data);
    delete gs;

    RetranslatorSatellite* rs = new RetranslatorSatellite();
    SatelliteAdapter* sa = new SatelliteAdapter(rs);

    sa->translate(data);

    delete sa;
    delete rs;
}

void composite() {
    MeterWaterTemperature* mwt = new MeterWaterTemperature();
    MeterWaterSpeed* mws = new MeterWaterSpeed();
    Sensor* sensor = new Sensor(mwt);
    Sensor* sensor2 = new Sensor(mws);
    
    MultiSensor* ms = new MultiSensor();
    ms->add(sensor);
    ms->add(sensor2);
    cout << ms->getChildren().size() << "\n";
    cout << ms->performMeter() << "\n";
    ms->remove(sensor);
    cout << ms->getChildren().size() << "\n";
    ms->remove(sensor2);

    delete sensor;
    delete sensor2;
    delete ms;
}

int main()
{
    int mode = 0;

    do {
        cout << "\n\nChoose mode:\n";
        cout << "Lab4 - 1\n";
        cout << "Adapter - 2\n";
        cout << "Composite - 3\n";
        cout << "Exit - 0\n";

        cin >> mode;

        switch (mode)
        {
        case 1:
            lab4();
            break;
        case 2:
            adapter();
            break;
        case 3:
            composite();
            break;
        default:
            break;
        }
    } while (mode != 0);

    return 0;
}