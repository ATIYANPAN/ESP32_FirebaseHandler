#ifndef FIREBASEHANDLER_H
#define FIREBASEHANDLER_H

#include <Arduino.h>
#include <FirebaseESP32.h>

class FirebaseHandler
{
public:
    FirebaseHandler();
    void begin(const char *host, const char *auth_token);
    bool sendInt(const String &path, int value);
    bool sendFloat(const String &path, float value);
    bool sendString(const String &path, const String &value);
    int receiveInt(const String &path);
    float receiveFloat(const String &path);
    String receiveString(const String &path);

private:
    FirebaseData fbdo;
    FirebaseAuth auth;
    FirebaseConfig config;
};

#endif
