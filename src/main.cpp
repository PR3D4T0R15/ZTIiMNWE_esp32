//biblioteka Arduino
#include <Arduino.h>
#include <ArduinoOTA.h>
//biblioteki do czujnika temperatury
#include <OneWire.h>
#include <DallasTemperature.h>
//biblioteki do karty SD
#include <SPI.h>
#include <SD.h>
//biblioteki do string
#include <string.h>


//Pin config (wybranie pinu na esp32 do podlaczenia)
const int oneWireBus = 4; 
const int errorPin = 25; 
const int correctPin = 26;

//Konfigurowanie instancji w celu komunikacji z innym urządzeniem OneWire
OneWire oneWire(oneWireBus);
//"Przekazanie" odniesienia oneWire do czujnika temperatury Dallas
DallasTemperature sensors(&oneWire);


//Funkcja pomiaru temperatury
float pomiar_temperatury()
{
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  return temperatureC;
}


//Funkcja dla diody led gdy uklad nie dziala poprawnie
void blad()
{
  digitalWrite(correctPin, LOW); 
  digitalWrite(errorPin, HIGH);
}


//Funkcja dla diody led gdy uklad dziala poprawnie
void dziala()
{
  digitalWrite(errorPin, LOW);
  digitalWrite(correctPin, HIGH);
}


//Odczytywanie danych z karty sd - SSID
std::string odczytajSSID()
{
  File plik = SD.open("/ustawienia.txt");
  while (plik.available())
  {
    Serial.write(plik.read());
  }
  plik.close();
  std::string output = "test";
  return output;
}


void setup()
{
  // Start the Serial Monitor
  Serial.begin(9600);
  // Start the DS18B20 sensor
  sensors.begin();
  //setup errorPin as output
  pinMode(errorPin, OUTPUT);
  //setup correctPin as output
  pinMode(correctPin, OUTPUT);
  SD.begin(5);
}


void loop()
{
  Serial.println("Zmierzona temperatura: ");
  Serial.print(pomiar_temperatury());
  Serial.println("ºC");
  delay(1000);
  //diody LED - monitoring
  blad();
  delay(1000);
  dziala();
  delay(1000);
  odczytajSSID();
}

