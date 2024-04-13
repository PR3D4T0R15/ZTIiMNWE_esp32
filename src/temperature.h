#pragma once

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//class
class temperature
{
private:
    OneWire _oneWire;
    DallasTemperature _sensor;

public:
    temperature(int OneWirePin);
    ~temperature();
    float getTemperature();
};
