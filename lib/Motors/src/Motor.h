#ifndef BALANCINGROBOT_MOTOR_H
#define BALANCINGROBOT_MOTOR_H

#include <Arduino.h>
#include <Wire.h>
#include <StepResolution.h>

class Motor {
private:
    bool invert;
    int stepPin;
    int directionPin;
    int ms1Pin;
    int ms2Pin;
    int ms3Pin;
    volatile bool currentStepState = false;
    volatile bool currentDirection = false;
    volatile StepResolution currentResolution = FULL;

public:
    Motor(uint8_t stepPin, uint8_t dirPin, uint8_t ms1Pin, uint8_t ms2Pin, uint8_t ms3Pin, bool invert);

    Motor(uint8_t stepPin, uint8_t dirPin, uint8_t ms1Pin, uint8_t ms2Pin, uint8_t ms3Pin);

    void init(StepResolution resolution);

    void setDirection(bool direction);

    void toggleStepState();

    void flushStepState() const;

    void setResolution(StepResolution resolution);

    void flushResolution() const;

    void flushDirection() const;
};


#endif //BALANCINGROBOT_MOTOR_H
