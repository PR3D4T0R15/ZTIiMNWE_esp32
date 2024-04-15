#include <Arduino.h>
#include <ArduinoOTA.h>

//bibloteka main
#include <main.h>
//biblioteka led
#include <led.h>
//biblioteka temperature
#include <temperature.h>
//biblioteka sdCard
#include <sdCard.h>
//biblioteka net
#include <netConn.h>
//biblioteka RTC
#include <rtcTime.h>

Temperature temp1(oneWireBus);
Led led1(errorPin, correctPin);
NetConn netWifi1("xxx","xxx");
RtcTime rtc1;
SdCard card1(spiSs);

void setup()
{
  Serial.begin(9600);
  temp1.begin();
  led1.begin();
  //netWifi.connect();
  rtc1.begin();
}


void loop()
{
  delay(2000);
  String val1 = card1.getSSID();
  String val2 = card1.getHaslo();
  Serial.println(val1);
  Serial.println(val2);
  delay(1000);
  led1.blad();
  delay(1000);
  led1.dziala();
}

