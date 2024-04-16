#pragma once

#include <RTClib.h>
#include <TimeLib.h>

class RtcTime
{
private:
    RTC_DS1307 _rtc;
public:
    RtcTime();
    ~RtcTime();
    void begin();
    DateTime getTime();
    void adjustTime(const DateTime data);
    void adjustTime(String date);
};