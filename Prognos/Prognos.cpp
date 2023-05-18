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
#include "Data.h"
#include <vector>
#include "DataStation.h"
#include "IStation.h"
#include "FMGidroStation.h"
#include "GroundStation.h"
#include "GidroStationCreator.h"
#include "GroundStationCreator.h"
#include "SlowSensorFactory.h"
#include "FastSensorFactory.h"
#include "WLSensor.h"
#include "WSSensor.h"

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
    Sensor* sensor = new Sensor(mws, "Sensor water speed");
    cout << "Water speed: " << sensor->performMeter()->getValue() << " M/S\n";
    delete sensor;

    MeterWaterTemperature* mwt = new MeterWaterTemperature();
    sensor = new Sensor(mwt, "Sensor water temperature");
    cout << "Water temperature: " << sensor->performMeter()->getValue() << " C\n";
    delete sensor;

    MeterWaterLevel* mwl = new MeterWaterLevel();
    sensor = new Sensor(mwl, "Sensor water level");
    cout << "Water level: " << sensor->performMeter()->getValue() << " M\n";
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
    Sensor* sensor = new Sensor(mwt, "Sensor water temperature");
    Sensor* sensor2 = new Sensor(mws, "Sensor water speed");
    MultiSensor* sensor3 = new MultiSensor();
    Sensor* sensor4 = new Sensor(mwt, "Sensor water temperature");
    Sensor* sensor5 = new Sensor(mws, "Sensor water speed");

    sensor3->add(sensor4);
    sensor3->add(sensor5);
    
    MultiSensor* ms = new MultiSensor();
    ms->add(sensor);
    ms->add(sensor3);
    ms->add(sensor2);
    
    cout << ms->getChildren().size() << "\n";
    Data::printTree(ms->performMeter(), 1);


    delete sensor;
    delete sensor2;
    delete ms;
}

void decorator() {
    MeterWaterSpeed* mws = new MeterWaterSpeed();
    Sensor* sensor = new Sensor(mws, "Sensor water speed with decorator");
    FormatDecorator* sensorWithDecorator = new FormatDecorator(sensor);
    
    cout << "Value changed on " << sensorWithDecorator->performMeter()->getValue() << " M/S in 4 seconds\n";
    
    delete sensorWithDecorator;
    delete sensor;
}

void iteratorf() {
    MeterWaterSpeed* mws = new MeterWaterSpeed();
    Sensor* sensor = new Sensor(mws, "Sensor water speed");
    MeterWaterSpeed* mws2 = new MeterWaterSpeed();
    Sensor* sensor2 = new Sensor(mws2, "Sensor water speed");
    MeterWaterSpeed* mws3 = new MeterWaterSpeed();
    Sensor* sensor3 = new Sensor(mws3, "Sensor water speed");
    MeterWaterSpeed* mws4 = new MeterWaterSpeed();
    Sensor* sensor4 = new Sensor(mws4, "Sensor water speed");

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

void singleton() {
    DataStation* datastation = DataStation::getInstance();
    datastation->pushValue(1);
    datastation->pushValue(2);
    datastation->pushValue(3);
    cout << "Data station 1 values: ";
    vector<int> values = datastation->getValues();
    for (int i = 0; i < values.size(); i++) cout << values[i] << " ";
    cout << "\n";

    DataStation* datastation2 = DataStation::getInstance();
    cout << "Data station 2 values: ";
    values = datastation->getValues();
    for (int i = 0; i < values.size(); i++) cout << values[i] << " ";
    cout << "\n";

    datastation2->pushValue(4);
    cout << "Data station 1 values after push in 2`nd version: ";
    values = datastation->getValues();
    for (int i = 0; i < values.size(); i++) cout << values[i] << " ";
    cout << "\n";
}

void factoryMethod() {
    GidroStationCreator* gsc = new GidroStationCreator();
    IStation* gs = gsc->createStation();
    vector<int> data = gs->collectData();
    GroundStationCreator* grsc = new GroundStationCreator();
    delete gs;
    gs = grsc->createStation();
    data = gs->collectData();
    delete gs;
}

void abstractFactory() {
    SlowSensorFactory* ssf = new SlowSensorFactory();
    FastSensorFactory* fsf = new FastSensorFactory();
    WSSensor* slowwss = ssf->createWSSensor();
    WSSensor* fastwss = fsf->createWSSensor();

    cout << "Slow water speed sensor value: " << slowwss->performMeter() << "\n";
    cout << "Fast water speed sensor value: " << fastwss->performMeter() << "\n";

    WLSensor* slowwls = ssf->createWLSensor();
    WLSensor* fastwls = fsf->createWLSensor();

    cout << "Slow water level sensor value: " << slowwls->performMeter() << "\n";
    cout << "Fast water level sensor value: " << fastwls->performMeter() << "\n";

    delete slowwls;
    delete fastwls;
    delete slowwss;
    delete fastwss;
    delete fsf;
    delete ssf;
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
        cout << "Singleton - 6\n";
        cout << "Factory Method - 7\n";
        cout << "Abstract factory - 8\n";
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
        case 6:
            singleton();
            break;
        case 7:
            factoryMethod();
            break;
        case 8:
            abstractFactory();
            break;
        default:
            break;
        }
    } while (mode != 0);

    return 0;
}