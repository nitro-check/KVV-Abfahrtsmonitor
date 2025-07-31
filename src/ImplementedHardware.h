#pragma once
#include <Arduino.h>
#include "ImplementedHardware/iHTEST.h"
#include "ImplementedHardware/iHWLAN.h"
#include "ImplementedHardware/iHKnob.h"

class ImplementedHardware {

private:
    //Pin assignment
    static const int testPin = 5;
    

    //Pin assignment for the knob
    static const int knobCLKPin = 34;
    static const int knobDTPin = 35;
    static const int knobSWPin = 32;


    //Instances of implemented Hardware
    iHTEST* test;
    iHWLAN* wlan;
    iHKnob* knob;

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
    iHKnob& getKnob() {
        return *knob;
    }
};