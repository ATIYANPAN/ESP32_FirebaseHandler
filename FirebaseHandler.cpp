#include "FirebaseHandler.h"

FirebaseHandler::FirebaseHandler() {}

void FirebaseHandler::begin(const char *host, const char *auth_token)
{
    config.host = host;
    config.signer.tokens.legacy_token = auth_token;
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}

bool FirebaseHandler::sendInt(const String &path, int value)
{
    if (Firebase.setInt(fbdo, path, value))
    {
        Serial.println("Int sent to Firebase.");
        return true;
    }
    else
    {
        Serial.println("Failed to send int: " + fbdo.errorReason());
        return false;
    }
}

bool FirebaseHandler::sendFloat(const String &path, float value)
{
    if (Firebase.setFloat(fbdo, path, value))
    {
        Serial.println("Float sent to Firebase.");
        return true;
    }
    else
    {
        Serial.println("Failed to send float: " + fbdo.errorReason());
        return false;
    }
}

bool FirebaseHandler::sendString(const String &path, const String &value)
{
    if (Firebase.setString(fbdo, path, value))
    {
        Serial.println("String sent to Firebase.");
        return true;
    }
    else
    {
        Serial.println("Failed to send string: " + fbdo.errorReason());
        return false;
    }
}

int FirebaseHandler::receiveInt(const String &path)
{
    if (Firebase.getInt(fbdo, path))
    {
        int val = fbdo.intData();
        Serial.print("Received Int: ");
        Serial.println(val);
        return val;
    }
    else
    {
        Serial.println("Failed to receive int: " + fbdo.errorReason());
        return 0;
    }
}

float FirebaseHandler::receiveFloat(const String &path)
{
    if (Firebase.getFloat(fbdo, path))
    {
        float val = fbdo.floatData();
        Serial.print("Received Float: ");
        Serial.println(val);
        return val;
    }
    else
    {
        Serial.println("Failed to receive float: " + fbdo.errorReason());
        return 0.0;
    }
}

String FirebaseHandler::receiveString(const String &path)
{
    if (Firebase.getString(fbdo, path))
    {
        String val = fbdo.stringData();
        Serial.print("Received String: ");
        Serial.println(val);
        return val;
    }
    else
    {
        Serial.println("Failed to receive string: " + fbdo.errorReason());
        return "";
    }
}
