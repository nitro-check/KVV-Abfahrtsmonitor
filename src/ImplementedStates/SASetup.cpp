#include "SASetup.h"

// Define the behavior of the Idle state
State SASetup::executeState(SystemVariables& sysVar) {

    return State::SETUP;
}

// Static instance and registration
static SASetup setupInstance;
static bool registeredSetup = StateRegistry::instance().registerState(&setupInstance);
