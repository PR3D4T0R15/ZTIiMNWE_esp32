#pragma once

#include <WiFi.h>

//class
class NetConn
{
private:
    String _ssid;
    String _pass;
public:
    NetConn(String ssid, String pass);
    ~NetConn();
    void connect();
    bool isConnected();
    String getIP();
};