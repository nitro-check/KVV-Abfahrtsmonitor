#include "iHTest.h"
#include <Arduino.h>

/**
 * @brief Constructs an iHMotor object with the specified pin.
 * 
 * @param pin The pin number to which the motor is connected.
 */
iHTest::iHTest(int pin) {
    // Initialize the test pin
    pinMode(pin, OUTPUT);
    this->testPin = pin;
}

/**
 * @brief Sets the speed of the motor in RPM.
 * 
 * @param rpm The desired speed in revolutions per minute.
 */
void iHTest::setTestSpeed(int rpm) {
    // Maps rpm from 0 to MAX_RPM to a PWM value between 0 and 255
    int pwmValue = map(rpm, 0, iHTest::MAX_TEST_RPM, 0, 255);
    analogWrite(this->testPin, pwmValue);
}

