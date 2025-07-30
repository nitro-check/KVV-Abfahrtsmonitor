#include "SASetup.h"

// Define the behavior of the Idle state
State SASetup::executeState(SystemVariables& sysVar) {
    Serial.println("ENTERING STATE: SETUP");

    return State::ConnectWLAN; // Transition to the next state
}

// Static instance and registration
static SASetup setupInstance;
static bool registeredSetup = StateRegistry::instance().registerState(&setupInstance);
