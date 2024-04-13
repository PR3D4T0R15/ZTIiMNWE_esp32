#include <sdCard.h>

sdCard::sdCard(int slaveSelect)
{
    _slaveSelect = slaveSelect;
    SD.begin(5);
    _fileSettings = SD.open("/ustawienia.txt");
}

sdCard::~sdCard()
{
    _fileSettings.close();
}

//Odczytywanie danych z karty sd - SSID
String sdCard::getSSID()
{
  File plik = SD.open("/ustawienia.txt");
  String linia;
  while (plik.available())
  {
    linia = plik.readStringUntil('\r');
    if(linia.indexOf("SSID=") != -1)
    {
      linia = linia.substring(5);
      Serial.print(linia);
    }    
  }
  plik.close();
  return linia;
}