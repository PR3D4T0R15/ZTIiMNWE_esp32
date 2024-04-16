#include <netConn.h>

NetConn::NetConn()
{
}

NetConn::~NetConn()
{
}

void NetConn::connect(const String ssid, const String pass)
{
    _ssid = ssid;
    _pass = pass;
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid, _pass);

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println(" OK");
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