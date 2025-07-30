#pragma once

#include "StateActionExecutor.h"
#include "State.h"
#include "SystemVariables.h"

class StateChangeController {
private:
    StateActionExecutor* executor;
    State* currentState;
    SystemVariables* sysVar;

public:
    StateChangeController(StateActionExecutor* exec, State* state, SystemVariables* sys);
    void start();
};
