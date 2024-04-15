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