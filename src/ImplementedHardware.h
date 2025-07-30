#pragma once
#include <Arduino.h>
#include "ImplementedHardware/iHTest.h"
#include "ImplementedHardware/iHWlan.h"

class ImplementedHardware {

private:
    //Pin assignment
    static const int testPin = 5;


    //Instances of implemented Hardware
    iHTEST* test;
    iHWLAN* wlan;

    //Next 4 lines are required for singleton pattern.
    ImplementedHardware();                            // Private constructor
    ImplementedHardware(const ImplementedHardware&) = delete; // Delete copy constructor
    ImplementedHardware& operator=(const ImplementedHardware&) = delete; // Delete assignment operator
public:
    static ImplementedHardware& getInstance();
    iHTEST& getTest() {
        return *test;
    }
    iHWLAN& getWlan() {
        return *wlan;
    }
};