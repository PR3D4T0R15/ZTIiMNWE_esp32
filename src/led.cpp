#include <led.h>
//biblioteka Arduino
#include <Arduino.h>
#include <ArduinoOTA.h>


led::led(int errPin, int corrPin)
{
    _errorPin = errPin;
    _correctPin = corrPin;
    //setup errorPin as output
    pinMode(_errorPin, OUTPUT);
    //setup correctPin as output
    pinMode(_correctPin, OUTPUT);
}

led::~led()
{
}

//Funkcja dla diody led gdy uklad nie dziala poprawnie
void led::blad()
{
    digitalWrite(_correctPin, LOW); 
    digitalWrite(_errorPin, HIGH);
}


//Funkcja dla diody led gdy uklad dziala poprawnie
void led::dziala()
{
    digitalWrite(_errorPin, LOW);
    digitalWrite(_correctPin, HIGH);
}