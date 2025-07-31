#pragma once

class iHKnob {
private:
    iHKnob() = delete; // Prevent default constructor
    int pinCLK; 
    int pinDT;
    int pinSW;
    int lastCLKState;
    int menuIndex = 0;
    int maxIndex = 1;
public:
    iHKnob(int pinCLK, int pinDT, int pinSW);
    void updateKnob();
    bool isPressed();
    int getMenuIndex();
    void resetKnobState();
};

