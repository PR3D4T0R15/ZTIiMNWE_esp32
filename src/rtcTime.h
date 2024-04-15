#pragma once

#include <RTClib.h>

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
};