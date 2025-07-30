#include "ImplementedHardware.h"

ImplementedHardware::ImplementedHardware(){
    ImplementedHardware::test = new iHTest(testPin);
}

ImplementedHardware& ImplementedHardware::getInstance() {
    static ImplementedHardware instance;
    return instance;
}