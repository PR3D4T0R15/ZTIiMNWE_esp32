#include <netConn.h>

NetConn::NetConn(String ssid, String pass)
{
    _ssid = ssid;
    _pass = pass;
    
}

NetConn::~NetConn()
{
}

void NetConn::connect()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid, _pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting...");
    }
}

bool NetConn::isConnected()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        return true;
    } else {
        return false;
    }
}

String NetConn::getIP()
{
    return WiFi.localIP().toString();
}