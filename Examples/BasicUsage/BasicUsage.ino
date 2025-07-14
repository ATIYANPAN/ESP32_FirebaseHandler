#include <WiFi.h>
#include <FirebaseHandler.h>

// WiFi credentials
#define WIFI_SSID "YourSSID"
#define WIFI_PASSWORD "YourPassword"

// Firebase credentials
#define FIREBASE_HOST "your-firebase-host"
#define FIREBASE_AUTH "your-auth-token"

        FirebaseHandler firebase;

void setup()
{
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop()
{
    firebase.sendInt("/Path/To/Int", 42);
    firebase.sendFloat("/Path/To/Float", 3.14);
    firebase.sendString("/Path/To/String", "ESP32 Firebase");

    firebase.receiveInt("/Path/To/Int");
    firebase.receiveFloat("/Path/To/Float");
    firebase.receiveString("/Path/To/String");

    delay(2000);
}