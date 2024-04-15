#pragma once

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <SPI.h>
#include <SD.h>

//class
class SdCard
{
private:
    int _slaveSelect;
public:
    SdCard(int slaveSelect);
    ~SdCard();
    String getSSID();
    String getHaslo();

};