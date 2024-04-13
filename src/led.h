#pragma once

class led
{
private:
    int _errorPin;
    int _correctPin;
public:
    led(int errPin, int corrPin);
    ~led();
    void dziala();
    void blad();
};