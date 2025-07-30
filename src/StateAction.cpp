#include "StateAction.h"

/**
 * @brief Default constructor for StateAction.
 * 
 * @note This constructor must remain empty.
 * Implemented StateActions are statically registered,
 * and any code in this constructor will be called too early,
 * potentially before variables are initialized.
 */
StateAction::StateAction() {
    // Constructor intentionally left empty.
}

/**
 * @brief Initializes the StateAction instance.
 * 
 * Implemented StateActions are statically registered.
 * Initialization occurs as a separate step after program execution,
 * so the constructor cannot contain initialization code.
 * This function should be called to initialize variables that require
 * fully constructed objects.
 */
void StateAction::init() {
    // Initialize the ImplementedHardware instance
    iH = &ImplementedHardware::getInstance();
}