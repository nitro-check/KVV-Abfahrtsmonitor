#pragma once
#include <Arduino.h>
#include "../SystemVariables.h"
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <Adafruit_GFX.h>
#include <u8g2_for_Adafruit_GFX.h>
class iHDisplay {
private:
    unsigned long lastDisplayUpdate = 0;
    int dR1Pin, dR2Pin, dB1Pin, dB2Pin, dG1Pin, dG2Pin;
    int dAPin, dBPin, dCPin, dDPin, dEPin;
    int dCLKPin, dLATPin, dOEPin;
    int displayWidth, displayHeight, numberOfPanels;
    MatrixPanel_I2S_DMA* matrix;
    
public:
    iHDisplay(int dR1Pin, int dR2Pin, int dB1Pin, int dB2Pin, int dG1Pin, int dG2Pin, 
                int dAPin, int dBPin, int dCPin, int dDPin, int dEPin,
                int dCLKPin, int dLATPin, int dOEPin,
                int displayWidth, int displayHeight, int numberOfPanels);
    void setLastDisplayUpdate(long now);
    long getLastDisplayUpdate();

    void writePopUp(String PopUpMsg);
    void clearDisplay();
    void fillDisplay(int r, int g, int b);
    void setBrightness(uint8_t brightness);
};