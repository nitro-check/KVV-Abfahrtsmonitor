#pragma once

#include "State.h"
#include "SystemVariables.h"
#include "ImplementedHardware.h"

class StateAction {
protected:
    State stateName;
    ImplementedHardware* iH;
public:
    StateAction();
    void init();
    virtual State getStateName() = 0;
    virtual State executeState(SystemVariables& sysVar) = 0;
};