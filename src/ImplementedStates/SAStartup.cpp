#include "SAStartup.h"

// Define the behavior of the Idle state
State SAStartup::executeState(SystemVariables& sysVar) {
    Serial.println("ENTERING STATE: STARTUP");
    iHDisplay& display = iH->getDisplay();

    
    display.writePopUp("STARTUP");
    return State::STARTUP; // Transition to the next state
}

// Static instance and registration
static SAStartup setupInstance;
static bool registeredSetup = StateRegistry::instance().registerState(&setupInstance);
