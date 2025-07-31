#include "iHDisplay.h"


iHDisplay::iHDisplay(int dR1Pin, int dR2Pin, int dB1Pin, int dB2Pin, 
                     int dG1Pin, int dG2Pin, int dAPin, int dBPin, 
                     int dCPin, int dDPin, 
                     int dCLKPin, int dLATPin, int dOEPin,
                     int displayWidth, int displayHeight, int numberOfPanels) {
    // Initialize the display pins
    pinMode(dR1Pin, OUTPUT);
    this->dR1Pin = dR1Pin;
    pinMode(dR2Pin, OUTPUT);
    this->dR2Pin = dR2Pin;
    pinMode(dB1Pin, OUTPUT);
    this->dB1Pin = dB1Pin;
    pinMode(dB2Pin, OUTPUT);
    this->dB2Pin = dB2Pin;
    pinMode(dG1Pin, OUTPUT);
    this->dG1Pin = dG1Pin;
    pinMode(dG2Pin, OUTPUT);
    this->dG2Pin = dG2Pin;
    pinMode(dAPin, OUTPUT);
    this->dAPin = dAPin;
    pinMode(dBPin, OUTPUT);
    this->dBPin = dBPin;
    pinMode(dCPin, OUTPUT);
    this->dCPin = dCPin;
    pinMode(dDPin, OUTPUT);
    this->dDPin = dDPin;
    pinMode(dCLKPin, OUTPUT);
    this->dCLKPin = dCLKPin;
    pinMode(dLATPin, OUTPUT);
    this->dLATPin = dLATPin;
    pinMode(dOEPin, OUTPUT);
    this->dOEPin = dOEPin;

    // Set the display parameters
    this->displayWidth = displayWidth;
    this->displayHeight = displayHeight;
    this->numberOfPanels = numberOfPanels;
}
     
void iHDisplay::setLastDisplayUpdate(long now) {
    lastDisplayUpdate = now; // Setzt den letzten Aktualisierungszeitpunkt
}

long iHDisplay::getLastDisplayUpdate() {
    return lastDisplayUpdate;
}