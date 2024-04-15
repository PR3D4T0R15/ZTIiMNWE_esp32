#pragma once

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//class
class Temperature
{
private:
    OneWire *_oneWire;
    DallasTemperature *_sensor;

public:
    Temperature(int OneWirePin);
    ~Temperature();
    void begin();
    float getTemperature();
};