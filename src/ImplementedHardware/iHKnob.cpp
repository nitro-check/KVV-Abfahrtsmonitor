#include "iHKnob.h"
#include <Arduino.h>

iHKnob::iHKnob(int pinCLK, int pinDT, int pinSW) {
    // Initialize the knob pins
    pinMode(pinCLK, INPUT);
    pinMode(pinDT, INPUT);
    pinMode(pinSW, INPUT_PULLUP);
    this->pinCLK = pinCLK;
    this->pinDT = pinDT;
    this->pinSW = pinSW;
    lastCLKState = digitalRead(pinCLK);
}

void iHKnob::updateKnob() {
  int currentCLKState = digitalRead(pinCLK);
  if (lastCLKState == HIGH && currentCLKState == LOW) {
    int dtState = digitalRead(pinDT);
    
    if (dtState == HIGH && menuIndex < maxIndex) menuIndex++;
    else if (dtState == LOW && menuIndex > 0) menuIndex--;
  }
  lastCLKState = currentCLKState;
}

bool iHKnob::isPressed() {
  return digitalRead(pinSW) == LOW;
}

int iHKnob::getMenuIndex() { 
  return menuIndex; 
}


void iHKnob::resetKnobState() { 
  menuIndex = 0; 
}