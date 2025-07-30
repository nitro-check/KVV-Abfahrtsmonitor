#include "SystemVariables.h"

SystemVariables::SystemVariables() : test(0.0f) {
    // Constructor initializes test variable to 0.0
}

float SystemVariables::getTest() {
    return test;
}

void SystemVariables::setTest(float value) {
    test = value;
}