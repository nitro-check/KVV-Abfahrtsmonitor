#pragma once

#include "../StateAction.h"  // Base class
#include "../StateRegistry.h" // Registry

class SAStartup : public StateAction {
public:
    virtual State getStateName() override {
        return State::STARTUP;
    }

    State executeState(SystemVariables& sysVar) override;  // Behavior defined in .cpp
};
