#pragma once

#include <Arduino.h>
#include <ArduinoOTA.h>

//class
class led
{
private:
    int _errorPin;
    int _correctPin;
public:
    led(int errPin, int corrPin);
    ~led();
    void dziala();
    void blad();
};