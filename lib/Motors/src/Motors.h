#ifndef BALANCINGROBOT_MOTORS_H
#define BALANCINGROBOT_MOTORS_H

#include <Arduino.h>
#include <Wire.h>


class Motors {
    int stepPin;
    volatile int directionPin;
    volatile int speed = 500;

public:
    explicit Motors(int stepPin, int dirPin);

    void init() const;

    void setSpeed(int newSpeed);

    void setDirection(bool direction) const;

    void setStepState(bool newState) const;
};


#endif //BALANCINGROBOT_MOTORS_H
