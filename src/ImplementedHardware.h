#pragma once
#include "ImplementedHardware/iHTest.h"
#include <Arduino.h>

class ImplementedHardware {

private:
    //Pin assignment
    static const int testPin = 5;

    //Instances of implemented Hardware
    iHTest* test;

    //Next 4 lines are required for singleton pattern.
    ImplementedHardware();                            // Private constructor
    ImplementedHardware(const ImplementedHardware&) = delete; // Delete copy constructor
    ImplementedHardware& operator=(const ImplementedHardware&) = delete; // Delete assignment operator
public:
    static ImplementedHardware& getInstance();
    iHTest& getTest() {
        return *test;
    }
};