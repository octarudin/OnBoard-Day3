#include "app.h"

// Replace with your network credentials
const char* ssid = "ANS19020924"; // ANS19020924 Aprian_Ext
const char* password = "PI130368"; // PI130368 telpwifi

HardwareSerial ser = Serial;

void app::start()
{
    ser.begin(115200);
    app::initWiFi();

    web::startKernel();
    temp::startKernel();
    rely::startKernel();
}

// Initialize WiFi
void app::initWiFi() 
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    ser.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        ser.print('.');
        delay(1000);
    }
    ser.println(WiFi.localIP());
}