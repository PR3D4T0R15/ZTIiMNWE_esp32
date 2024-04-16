#include <rtcTime.h>

RtcTime::RtcTime()
{
}

RtcTime::~RtcTime()
{
}

void RtcTime::begin()
{
    _rtc.begin();
}

DateTime RtcTime::getTime()
{
    return _rtc.now();
}

void RtcTime::adjustTime(const DateTime data)
{
    _rtc.adjust(data);
}

void RtcTime::adjustTime(String date)
{
    struct tm dt;
    strptime(date.c_str(), "%Y-%m-%dT%H:%M:%S", &dt);
    time_t t = mktime(&dt);
    DateTime dateTime = DateTime(t);

    _rtc.adjust(dateTime);
}