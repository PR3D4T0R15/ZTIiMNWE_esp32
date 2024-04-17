#include <Arduino.h>
#include <ArduinoOTA.h>
#include <esp_sleep.h>

#include <led.h>
#include <temperature.h>
#include <sdCard.h>
#include <netConn.h>
#include <RequestClient.h>
#include <rtcTime.h>

#define usInS 1000000
#define sInMin 60
#define oneWireBus  4
#define spiSs  5
#define errorPin  25
#define correctPin  26


void setup()
{ 
  Serial.begin(9600);
  Serial.println("## WAKEUP ##");
  Led led1(errorPin, correctPin);
  led1.begin();
  led1.init();

  SdCard card1(spiSs);
  String ssid = card1.getSSID();
  String pass = card1.getHaslo();
  String url = card1.getUrl();
  String auth = card1.getAuth();

  //setup http led rtc temp
  RequestClient req1(url, auth);
  NetConn netWifi1;
  
  RtcTime rtc1;
  Temperature temp1(oneWireBus);

  //io devices
  temp1.begin();
  rtc1.begin();
    
  //connect to wifi
  netWifi1.connect(ssid, pass);
  Serial.println("IP: " + netWifi1.getIP());

  //update RTC time
  String time = req1.getTime();
  rtc1.adjustTime(time);

  //get temp and time
  float tempValue = temp1.getTemperature();
  DateTime timeValue = rtc1.getTime();

  //send temp
  bool status = req1.sendData(tempValue, timeValue);

  if (status)
  {
    led1.working();
    delay(2000);
    Serial.println("SLEEP...");
    led1.off();
    Serial.flush();
    esp_sleep_enable_timer_wakeup(10 * 1000000);
    esp_deep_sleep_start();
  }else
  {
    led1.error();
    Serial.println("ERROR...");
    while (1)
    {
      Serial.println("ERROR!");
      delay(2000);
    }
    
  }
}


void loop()
{
}

