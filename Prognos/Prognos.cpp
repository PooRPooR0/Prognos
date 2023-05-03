#include <iostream>
#include "ProxyGidroStation.h"
#include "Antenna.h"
#include "Wire.h"

int main()
{
    ProxyGidroStation* gs = new ProxyGidroStation();
    gs->collectData();
    delete gs;

    Antenna* antena = new Antenna(2);
    antena->performTransmission();
    delete antena;

    Wire* wire = new Wire(5);
    wire->performTransmission();
    delete wire;

    return 0;
}