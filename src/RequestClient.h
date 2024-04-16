#pragma once

#include <HTTPClient.h>
#include <ArduinoJson.h>

class RequestClient
{
private:
    String _url;
    String _auth;
public:
    RequestClient(String url, String auth);
    ~RequestClient();

    //requests
    String ping();
    bool sendData(float value);
    String getTime();
};