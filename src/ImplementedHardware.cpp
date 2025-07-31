#include "ImplementedHardware.h"

ImplementedHardware::ImplementedHardware(){
    ImplementedHardware::test = new iHTEST(testPin);
    ImplementedHardware::wlan = new iHWLAN("Kriegsfuehrungssquad", "py2kdafvZkrd");
    ImplementedHardware::knob = new iHKnob(knobCLKPin, knobDTPin, knobSWPin);
    ImplementedHardware::display = new iHDisplay(dR1Pin, dR2Pin, dB1Pin, dB2Pin, dG1Pin, dG2Pin, dAPin, dBPin, dCPin, dDPin, dCLKPin, dLATPin, dOEPin, displayWitdh, displayHeigth, nomberOfPanels);
}

ImplementedHardware& ImplementedHardware::getInstance() {
    static ImplementedHardware instance;
    return instance;
}