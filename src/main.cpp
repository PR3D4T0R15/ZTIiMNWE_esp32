//biblioteka Arduino
#include <Arduino.h>
#include <ArduinoOTA.h>
//biblioteki do karty SD
#include <SPI.h>
#include <SD.h>
//biblioteki do string
#include <string.h>

//biblioteka led
#include <led.h>

//bibloteka main
#include <main.h>

//Odczytywanie danych z karty sd - SSID
std::string odczytajSSID()
{
  File plik = SD.open("/ustawienia.txt");
  while (plik.available())
  {
    String linia = plik.readStringUntil('\r');
    if(linia.indexOf("SSID=") != -1)
    {
      linia = linia.substring(5);
      Serial.print(linia);
    }    
  }
  plik.close();
  std::string output = "test";
  return output;
}


void setup()
{
  // Start the Serial Monitor
  // Start the DS18B20 sensor

  SD.begin(5);
}


void loop()
{
}

