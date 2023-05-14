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
#include "FormatDecorator.h"
#include "Sensors.h"
#include "SensorsIterator.h"
#include <ctime>

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

void decorator() {
    MeterWaterSpeed* mws = new MeterWaterSpeed();
    Sensor* sensor = new Sensor(mws);

    cout << sensor->performMeter() << " M/S\n";
    FormatDecorator* sensorWithDecorator = new FormatDecorator(sensor);
    cout << sensorWithDecorator->performMeter() << " SM/S\n";
    
    delete sensorWithDecorator;
    delete sensor;
}

void iteratorf() {
    MeterWaterSpeed* mws = new MeterWaterSpeed();
    Sensor* sensor = new Sensor(mws);
    MeterWaterSpeed* mws2 = new MeterWaterSpeed();
    Sensor* sensor2 = new Sensor(mws2);
    MeterWaterSpeed* mws3 = new MeterWaterSpeed();
    Sensor* sensor3 = new Sensor(mws3);
    MeterWaterSpeed* mws4 = new MeterWaterSpeed();
    Sensor* sensor4 = new Sensor(mws4);

    Sensors* s = new Sensors();
    s->addSensor(sensor);
    s->addSensor(sensor2);
    s->addSensor(sensor3);
    s->addSensor(sensor4);

    GidroStation* gs = new GidroStation(s);
    gs->collectData();
    
    delete gs;
    delete sensor;
    delete sensor2;
    delete sensor3;
    delete sensor4;
    delete s;
}

int main()
{
    int mode = 0;
    srand(time(0));

    do {
        cout << "\n\nChoose mode:\n";
        cout << "Lab4 - 1\n";
        cout << "Adapter - 2\n";
        cout << "Composite - 3\n";
        cout << "Decorator - 4\n";
        cout << "Iterator - 5\n";
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
        case 4:
            decorator();
            break;
        case 5:
            iteratorf();
            break;
        default:
            break;
        }
    } while (mode != 0);

    return 0;
}