#include <RequestClient.h>

RequestClient::RequestClient(String url, String auth)
{
    _url = url;
    _auth = auth;
}

RequestClient::~RequestClient()
{
}

String RequestClient::ping()
{
    HTTPClient http;
    http.begin(_url + "/ping");

    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String(_auth));

    int responseCode = http.GET();
    
    if (responseCode == 200)
    {
        String data = http.getString();
        return data;
    } else
    {
        return "ERROR";
    }

    http.end();
}

bool RequestClient::sendData(float value, DateTime time)
{
    HTTPClient http;
    http.begin(_url + "/data");

    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String(_auth));

    String Body = "";
    JsonDocument doc;
    doc["temp"] = value;
    doc["time"] = time.timestamp();
    serializeJson(doc, Body);

    int response = http.POST(Body);
    if (response == 200)
    {
        Serial.println("POST..OK");
        return true;
    }else
    {
        return false;
    }
    
    
}

String RequestClient::getTime()
{
    HTTPClient http;
    http.begin(_url + "/time");

    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String(_auth));

    int responseCode = http.GET();

    if (responseCode = 200)
    {
        String data = http.getString();

        JsonDocument doc;
        deserializeJson(doc, data);
        String date = doc["time"];
        return date;
    } else
    {
        return "ERROR";
    }

    http.end();
}