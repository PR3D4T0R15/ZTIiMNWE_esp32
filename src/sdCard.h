#pragma once

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <SPI.h>
#include <SD.h>

//class
class sdCard
{
private:
    int _slaveSelect;
    File _fileSettings;
public:
    sdCard(int slaveSelect);
    ~sdCard();
    String getSSID();
    String getHaslo();

};