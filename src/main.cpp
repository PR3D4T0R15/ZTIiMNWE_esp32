#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>


// Pin config (wybranie pinu na esp32 do podlaczenia)
const int oneWireBus = 4; 
const int errorPin = 25; 
const int correctPin = 26;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

float pomiar_temperatury()
{
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  return temperatureC;
}

void blad()
{
  digitalWrite(correctPin, LOW);
  digitalWrite(errorPin, HIGH);
}

void dziala()
{
  digitalWrite(errorPin, LOW);
  digitalWrite(correctPin, HIGH);
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
}

