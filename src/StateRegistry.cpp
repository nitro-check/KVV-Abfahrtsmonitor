#include "StateRegistry.h"

/**
 * @brief Returns the singleton instance of the StateRegistry.
 * 
 * @return Reference to the singleton StateRegistry object.
 */
StateRegistry& StateRegistry::instance() {
    static StateRegistry registry;
    return registry;
}

/**
 * @brief Constructs a StateRegistry and initializes all state pointers to nullptr.
 */
StateRegistry::StateRegistry() {
    // Initialize all state pointers to nullptr
    for (int i = 0; i < MAX_STATES; ++i) {
        states[i] = nullptr;
    }
}

/**
 * @brief Registers a StateAction for a specific state.
 * 
 * Registers the given StateAction pointer in the registry if the corresponding
 * state slot is empty and the index is valid.
 * 
 * @param state Pointer to the StateAction to register.
 * @return true if registration was successful, false otherwise.
 */
bool StateRegistry::registerState(StateAction* state) {
    // State.h is a class and can be converted to an int.
    int index = static_cast<int>(state->getStateName());
    if (index >= 0 && index < MAX_STATES && states[index] == nullptr) {
        states[index] = state;
        return true;
    }
    return false;
}

/**
 * @brief Retrieves the StateAction associated with a given state.
 * 
 * Returns a pointer to the StateAction corresponding to the given state.
 * If the state is not registered, returns nullptr.
 * 
 * @param s The state for which to retrieve the StateAction.
 * @return Pointer to the StateAction associated with the state, or nullptr if not found.
 */
StateAction* StateRegistry::getState(State s) {
    int index = static_cast<int>(s);
    if (index >= 0 && index < MAX_STATES) {
        return states[index];
    }
    return nullptr;
}
