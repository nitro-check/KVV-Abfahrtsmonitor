#pragma once
#include "State.h"
#include "StateAction.h"

class StateRegistry {
public:
    static const int MAX_STATES = static_cast<int>(State::COUNT);
    static StateRegistry& instance();

    bool registerState(StateAction* state);
    StateAction* getState(State state);

private:
    StateAction* states[MAX_STATES];
    StateRegistry();
};
