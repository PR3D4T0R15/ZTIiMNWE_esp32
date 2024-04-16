#pragma once

#include <Arduino.h>
#include <ArduinoOTA.h>

//class
class Led
{
private:
    int _errorPin;
    int _correctPin;
public:
    Led(int errPin, int corrPin);
    ~Led();
    void begin();
    void init();
    void working();
    void error();
};