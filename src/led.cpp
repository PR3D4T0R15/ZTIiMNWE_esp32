#include <led.h>


Led::Led(int errPin, int corrPin)
{
    _errorPin = errPin;
    _correctPin = corrPin;
}

Led::~Led()
{
}

void Led::begin()
{
    pinMode(_errorPin, OUTPUT);
    pinMode(_correctPin, OUTPUT);
}

//Funkcja dla diody led gdy uklad nie dziala poprawnie
void Led::blad()
{
    digitalWrite(_correctPin, LOW); 
    digitalWrite(_errorPin, HIGH);
}


//Funkcja dla diody led gdy uklad dziala poprawnie
void Led::dziala()
{
    digitalWrite(_errorPin, LOW);
    digitalWrite(_correctPin, HIGH);
}