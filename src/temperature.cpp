#include <temperature.h>

Temperature::Temperature(int OneWirePin)
{
    _oneWire = new OneWire(OneWirePin);
    _sensor = new DallasTemperature(_oneWire);
}

Temperature::~Temperature()
{
}

void Temperature::begin()
{
    _sensor->begin();
}

float Temperature::getTemperature()
{
    //request temp - all sensors do a temp conv
    _sensor->requestTemperatures();

    //get temp - get temp form device of index 0
    return _sensor->getTempCByIndex(0);
}