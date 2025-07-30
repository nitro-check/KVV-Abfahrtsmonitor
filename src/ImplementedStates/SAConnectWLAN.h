#pragma once

#include "../StateAction.h"  // Base class
#include "../StateRegistry.h" // Registry

class SAConnectWLAN : public StateAction {
public:
    virtual State getStateName() override {
        return State::ConnectWLAN;
    }

    State executeState(SystemVariables& sysVar) override;  // Behavior defined in .cpp
};
