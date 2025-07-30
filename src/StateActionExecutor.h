#pragma once

#include <Arduino.h>
#include "StateAction.h"
#include "State.h"
#include "SystemVariables.h"
#include "StateRegistry.h" 

class StateActionExecutor {
public:
    StateActionExecutor();
    State executeStateAction(State state, SystemVariables& sysVar);
};
