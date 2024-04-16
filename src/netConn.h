#pragma once

#include <WiFi.h>


//class
class NetConn
{
private:
    String _ssid;
    String _pass;
    String _url;
public:
    NetConn();
    ~NetConn();
    void connect(String ssid, String pass);
    bool isConnected();
    String getIP();
};