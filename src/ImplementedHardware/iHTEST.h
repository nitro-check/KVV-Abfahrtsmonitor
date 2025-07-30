#pragma once

class iHTest {
private:
    iHTest() = delete; // Prevent default constructor
    int testPin; // Pin to which the motor is connected
    static const int MAX_TEST_RPM = 100; // Maximum RPM for the motor
public:
    iHTest(int pin);
    void setTestSpeed(int rpm);
};