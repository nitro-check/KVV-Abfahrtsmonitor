#include "SAConnectWLAN.h"

// Define the behavior of the Idle state
State SAConnectWLAN::executeState(SystemVariables& sysVar) {
    Serial.println("ENTERING STATE: ConnectWLAN");

    iHWLAN& wlan = iH->getWlan();
    wlan.connect();
    while (!wlan.isConnected()) {
        Serial.print("WLAN-Verbindung wird aufgebaut");// Wait for the WLAN connection to be established
        delay(1000); // Adjust the delay as needed
    }
    return State::ConnectWLAN; // Transition to the next state
}

// Static instance and registration
static SAConnectWLAN setupInstance;
static bool registeredSetup = StateRegistry::instance().registerState(&setupInstance);
