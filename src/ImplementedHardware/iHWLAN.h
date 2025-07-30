#include <Arduino.h>
#include <WiFi.h>

class iHWLAN {
public:
    iHWLAN(const char* ssid, const char* password);
    void connect();
    void disconnect();
    bool isConnected();

private:
    const char* _ssid;
    const char* _password;
};
