#pragma once
#include <Arduino.h>
#include "ImplementedHardware/iHTEST.h"
#include "ImplementedHardware/iHWLAN.h"
#include "ImplementedHardware/iHKnob.h"
#include "ImplementedHardware/iHDisplay.h"

class ImplementedHardware {

private:
    //Pin assignment
    static const int testPin = 5;
    

    //Pin assignment for the knob
    static const int knobCLKPin = 34;
    static const int knobDTPin = 35;
    static const int knobSWPin = 32;

    //Pin assignment for the display
    static const int dR1Pin = 25; 
    static const int dR2Pin = 14;
    static const int dB1Pin = 27;
    static const int dB2Pin = 13;
    static const int dG1Pin = 26;
    static const int dG2Pin = 12;
    static const int dAPin = 23;
    static const int dBPin = 19;
    static const int dCPin = 5;
    static const int dDPin = 17;
    static const int dCLKPin = 16;
    static const int dLATPin = 4;
    static const int dOEPin = 15;

    //display parameters
    static const int displayWitdh = 64;
    static const int displayHeigth = 32;
    static const int nomberOfPanels = 1;

    //Instances of implemented Hardware
    iHTEST* test;
    iHWLAN* wlan;
    iHKnob* knob;
    iHDisplay* display;

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
    iHDisplay& getDisplay() {
        return *display;
    }
};