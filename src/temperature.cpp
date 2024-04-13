#include <temperature.h>

temperature::temperature(int OneWirePin)
{
    OneWire* _oneWire = new OneWire(OneWirePin);
    DallasTemperature* _sensor = new DallasTemperature(_oneWire);

    _sensor->begin();
}

temperature::~temperature()
{
    delete &_sensor;
    delete &_oneWire;
}

float temperature::getTemperature()
{
    //request temp - all sensors do a temp conv
    _sensor.requestTemperatures();

    //get temp - get temp form device of index 0
    return _sensor.getTempCByIndex(0);
}