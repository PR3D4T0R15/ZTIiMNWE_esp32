#include <sdCard.h>

SdCard::SdCard(int slaveSelect)
{
    _slaveSelect = slaveSelect;
    SD.begin(5);
}

SdCard::~SdCard()
{
}

//Odczytywanie danych z karty sd - SSID
String SdCard::getSSID()
{
  File plik = SD.open("/ustawienia.txt");
  String slowo;
  while (plik.available())
  {
    String linia = plik.readStringUntil('\n');
    if(linia.indexOf("SSID=") != -1)
    {
      slowo = linia.substring(5);
      break;
    }    
  }
  plik.close();
  return slowo;
}

String SdCard::getHaslo()
{
  File plik = SD.open("/ustawienia.txt");
  String slowo;
  while (plik.available())
  {
    String linia = plik.readStringUntil('\n');
    if(linia.indexOf("Haslo=") != -1)
    {
      slowo = linia.substring(6);
      break;
    }    
  }
  plik.close();
  return slowo;
}