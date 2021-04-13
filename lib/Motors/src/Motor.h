#ifndef BALANCINGROBOT_MOTOR_H
#define BALANCINGROBOT_MOTOR_H

#include <Arduino.h>
#include <Wire.h>

class Motor {
private:
    bool invert;
    int stepPin;
    int directionPin;

public:
    Motor(uint8_t stepPin, uint8_t dirPin, bool invert);

    Motor(uint8_t stepPin, uint8_t dirPin);

    void init() const;

    void setDirection(bool direction) const;

    void setStepState(bool newState) const;

};


#endif //BALANCINGROBOT_MOTOR_H
