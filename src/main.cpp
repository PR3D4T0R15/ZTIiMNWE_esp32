#include <Arduino.h>
#include <ArduinoOTA.h>
#include <esp_sleep.h>

#include <led.h>
#include <temperature.h>
#include <sdCard.h>
#include <netConn.h>
#include <RequestClient.h>
#include <rtcTime.h>

#define TIME_TO_SLEEP 1800000000
#define oneWireBus  4
#define spiSs  5
#define errorPin  25
#define correctPin  26


void setup()
{
  //serial console
  Serial.begin(9600);
  Serial.println("## WAKEUP ##");

  SdCard card1(spiSs);
  //get wifi conf
  String ssid = card1.getSSID();
  String pass = card1.getHaslo();
  String url = card1.getUrl();
  String auth = card1.getUrl();


  RequestClient req1(url, auth);
  Led led1(errorPin, correctPin);
  NetConn netWifi1;
  RtcTime rtc1;
  Temperature temp1(oneWireBus);

  //io devices
  temp1.begin();
  led1.begin();
  rtc1.begin();

  //setup stage info
  led1.init();
    
  //connect to wifi
  netWifi1.connect(ssid, pass);
  Serial.println("IP: " + netWifi1.getIP());

  //update RTC time
  String time = req1.getTime();
  rtc1.adjustTime(time);
}


void loop()
{
  led1.working();
  
  delay(1000);
  Serial.println(rtc1.getTime().timestamp());
  led1.error();
  delay(10000);
}

