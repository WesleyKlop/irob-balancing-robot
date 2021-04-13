#ifndef BALANCINGROBOT_MOTOR_H
#define BALANCINGROBOT_MOTOR_H

#include <Arduino.h>
#include <Wire.h>


class Motor {
private:
    bool invert;
    int stepPin;
    volatile int directionPin;
    volatile int speed = 500;

public:
    Motor(uint8_t stepPin, uint8_t dirPin, bool invert);

    Motor(uint8_t stepPin, uint8_t dirPin);

    void init() const;

    void setSpeed(int newSpeed);

    void setDirection(bool direction) const;

    void setStepState(bool newState) const;

};


#endif //BALANCINGROBOT_MOTOR_H
