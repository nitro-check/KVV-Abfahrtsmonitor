#include "ImplementedHardware.h"

ImplementedHardware::ImplementedHardware(){
    ImplementedHardware::test = new iHTEST(testPin);
    ImplementedHardware::wlan = new iHWLAN("Kriegsfuehrungssquad", "py2kdafvZkrd");
    ImplementedHardware::knob = new iHKnob(knobCLKPin, knobDTPin, knobSWPin);
}

ImplementedHardware& ImplementedHardware::getInstance() {
    static ImplementedHardware instance;
    return instance;
}