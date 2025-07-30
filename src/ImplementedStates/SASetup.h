#pragma once

#include "../StateAction.h"  // Base class
#include "../StateRegistry.h" // Registry

class SASetup : public StateAction {
public:
    virtual State getStateName() override {
        return State::SETUP;
    }

    State executeState(SystemVariables& sysVar) override;  // Behavior defined in .cpp
};
