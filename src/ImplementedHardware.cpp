#include "ImplementedHardware.h"

ImplementedHardware::ImplementedHardware(){
    ImplementedHardware::test = new iHTEST(testPin);
    ImplementedHardware::wlan = new iHWLAN("Kriegsfuehrungssquad", "py2kdafvZkrd");
}

ImplementedHardware& ImplementedHardware::getInstance() {
    static ImplementedHardware instance;
    return instance;
}