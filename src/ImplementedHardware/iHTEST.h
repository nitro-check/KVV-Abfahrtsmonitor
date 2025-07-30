#pragma once

class iHTEST {
private:
    iHTEST() = delete; // Prevent default constructor
    int testPin; // Pin to which the motor is connected
    static const int MAX_TEST_RPM = 100; // Maximum RPM for the motor
public:
    iHTEST(int pin);
    void setTestSpeed(int rpm);
};