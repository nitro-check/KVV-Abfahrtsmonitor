#include "iHWLAN.h"

iHWLAN::iHWLAN(const char* ssid, const char* password)
    : _ssid(ssid), _password(password) {}

void iHWLAN::connect() {
    WiFi.begin(_ssid, _password);
    // Optional: Warte auf Verbindung
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
        delay(100);
    }
}

void iHWLAN::disconnect() {
    WiFi.disconnect();
}

bool iHWLAN::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}