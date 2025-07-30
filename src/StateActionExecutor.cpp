#include <Arduino.h>
#include "StateActionExecutor.h"

/**
 * @brief Constructs a StateActionExecutor object.
 * 
 * This constructor initializes all registered StateAction instances.
 */
StateActionExecutor::StateActionExecutor() {
    //Call the init method of each StateAction to ensure they are properly initialized.
    for (int i = 0; i < StateRegistry::MAX_STATES; ++i) {
        StateAction* action = StateRegistry::instance().getState(static_cast<State>(i));
        if (action != nullptr) {
            action->init();  // Initialize the StateAction instance
        }
    }
}


/**
 * @brief Executes the StateAction corresponding to the given state.
 * 
 * Converts the state to an index and calls the executeState method of the corresponding StateAction.
 * If no StateAction is registered for the state, returns the input state.
 * 
 * @param state The state whose action should be executed.
 * @param sysVar Reference to the system variables.
 * @return The resulting state after execution.
 */
State StateActionExecutor::executeStateAction(State state, SystemVariables& sysVar) {
    // Get the StateAction from the registry.
    StateAction* chosenAction = StateRegistry::instance().getState(state);
    if (chosenAction != nullptr) {
        return chosenAction->executeState(sysVar);
    }
    // If no action is registered for the state, return the input state.
    return state;
}
