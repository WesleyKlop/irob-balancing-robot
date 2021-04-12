#ifndef BALANCINGROBOT_MOTORS_H
#define BALANCINGROBOT_MOTORS_H

#include <Arduino.h>
#include <Wire.h>


class Motors {
    int stepPin;
    int directionPin;
    int speed = 500;

public:
    explicit Motors(int stepPin, int dirPin);

    void init() const;

    void step() const;

    void setSpeed(int newSpeed);

    void setDirection(bool direction);

};


#endif //BALANCINGROBOT_MOTORS_H
