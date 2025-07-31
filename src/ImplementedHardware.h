#pragma once
#include <Arduino.h>
#include "ImplementedHardware/iHTEST.h"
#include "ImplementedHardware/iHWLAN.h"
#include "ImplementedHardware/iHKnob.h"
#include "ImplementedHardware/iHDisplay.h"

class ImplementedHardware {

private:
    //Pin assignment
    static const int testPin = 2;
    

    //Pin assignment for the knob
    static const int knobCLKPin = 34;
    static const int knobDTPin = 35;
    static const int knobSWPin = 33;

    //Pin assignment for the display
    static const int dR1Pin = 19; 
    static const int dR2Pin = 5;
    static const int dB1Pin = 18;
    static const int dB2Pin = 17;
    static const int dG1Pin = 32;
    static const int dG2Pin = 25;
    static const int dAPin = 16;
    static const int dBPin = 27;
    static const int dCPin = 4;
    static const int dDPin = 14; 
    static const int dEPin = 26;
    static const int dCLKPin = 23;
    static const int dLATPin = 12;
    static const int dOEPin = 22;

    //display parameters
    static const int displayWidth = 64;
    static const int displayHeight = 64;
    static const int numberOfPanels = 3;

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