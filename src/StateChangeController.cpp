#include "StateChangeController.h"

StateChangeController::StateChangeController(StateActionExecutor* exec, State* state, SystemVariables* sys)
    : executor(exec), currentState(state), sysVar(sys) {
    // Initialize the controller with the provided executor, state, and system variables
}

void StateChangeController::start() {
    // Start the state change process
    while (true) {
        // Execute the current state action and get the next state
        *currentState = executor->executeStateAction(*currentState, *sysVar);
    }
}
