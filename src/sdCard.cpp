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
      int start = linia.indexOf('=');
      start++;
      
      int stop = linia.indexOf('\r');
      
      slowo = linia.substring(start, stop);
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
      int start = linia.indexOf('=');
      start++;

      int stop = linia.indexOf('\r');

      slowo = linia.substring(start, stop);
      break;
    }    
  }
  plik.close();
  return slowo;
}

String SdCard::getUrl()
{
  File plik = SD.open("/ustawienia.txt");
  String slowo;
  while (plik.available())
  {
    String linia = plik.readStringUntil('\n');
    if(linia.indexOf("Url=") != -1)
    {
      int start = linia.indexOf('=');
      start++;

      int stop = linia.indexOf('\r');

      slowo = linia.substring(start, stop);
      break;
    }    
  }
  plik.close();
  return slowo;
}

String SdCard::getAuth()
{
  File plik = SD.open("/ustawienia.txt");
  String slowo;
  while (plik.available())
  {
    String linia = plik.readStringUntil('\n');
    if(linia.indexOf("Auth=") != -1)
    {
      int start = linia.indexOf('=');
      start++;

      int stop = linia.indexOf('\r');

      slowo = linia.substring(start, stop);
      break;
    }    
  }
  plik.close();
  return slowo;
}