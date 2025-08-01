#include "iHDisplay.h"

iHDisplay::iHDisplay(int dR1Pin, int dR2Pin, int dB1Pin, int dB2Pin,
                     int dG1Pin, int dG2Pin, int dAPin, int dBPin,
                     int dCPin, int dDPin, int dEPin,
                     int dCLKPin, int dLATPin, int dOEPin,
                     int displayWidth, int displayHeight, int numberOfPanels)
    : dR1Pin(dR1Pin), dR2Pin(dR2Pin), dB1Pin(dB1Pin), dB2Pin(dB2Pin),
      dG1Pin(dG1Pin), dG2Pin(dG2Pin), dAPin(dAPin), dBPin(dBPin), dCPin(dCPin), dDPin(dDPin), dEPin(dEPin),
      dCLKPin(dCLKPin), dLATPin(dLATPin), dOEPin(dOEPin),
      displayWidth(displayWidth), displayHeight(displayHeight), numberOfPanels(numberOfPanels)
{
    // Pin-Initialisierung (optional, falls du sie brauchst)
    pinMode(dR1Pin, OUTPUT);
    pinMode(dR2Pin, OUTPUT);
    pinMode(dB1Pin, OUTPUT);
    pinMode(dB2Pin, OUTPUT);
    pinMode(dG1Pin, OUTPUT);
    pinMode(dG2Pin, OUTPUT);
    pinMode(dAPin, OUTPUT);
    pinMode(dBPin, OUTPUT);
    pinMode(dCPin, OUTPUT);
    pinMode(dDPin, OUTPUT);
    pinMode(dEPin, OUTPUT);
    pinMode(dCLKPin, OUTPUT);
    pinMode(dLATPin, OUTPUT);
    pinMode(dOEPin, OUTPUT);

    // Matrix-Konfiguration
    HUB75_I2S_CFG mxconfig;
    mxconfig.gpio.r1 = dR1Pin;
    mxconfig.gpio.g1 = dG1Pin;
    mxconfig.gpio.b1 = dB1Pin;
    mxconfig.gpio.r2 = dR2Pin;
    mxconfig.gpio.g2 = dG2Pin;
    mxconfig.gpio.b2 = dB2Pin;
    mxconfig.gpio.a = dAPin;
    mxconfig.gpio.b = dBPin;
    mxconfig.gpio.c = dCPin;
    mxconfig.gpio.d = dDPin;
    mxconfig.gpio.e = dEPin;
    mxconfig.gpio.lat = dLATPin;
    mxconfig.gpio.oe = dOEPin;
    mxconfig.gpio.clk = dCLKPin;

    mxconfig.mx_width = displayWidth;
    mxconfig.mx_height = displayHeight;
    mxconfig.chain_length = numberOfPanels;
    mxconfig.i2sspeed = HUB75_I2S_CFG::HZ_20M;  // statt HZ_20M


    mxconfig.driver = HUB75_I2S_CFG::SHIFTREG;

    matrix = new MatrixPanel_I2S_DMA(mxconfig);
    matrix->begin();
}

void iHDisplay::setLastDisplayUpdate(long now) {
    lastDisplayUpdate = now;
}

long iHDisplay::getLastDisplayUpdate() {
    return lastDisplayUpdate;
}

void iHDisplay::writePopUp(String PopUpMsg) {
    matrix->setTextColor(matrix->color565(255, 130, 15));
    matrix->setCursor(12, 12);
    matrix->print(PopUpMsg);
}
void iHDisplay::clearDisplay() {
    matrix->fillScreen(matrix->color565(0, 0, 0));
}

void iHDisplay::fillDisplay(int r, int g, int b) {
    matrix->fillScreen(matrix->color565(r, g, b));
}

void iHDisplay::setBrightness(uint8_t brightness) {
    matrix->setBrightness(brightness);
}
    