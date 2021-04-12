#ifndef BALANCINGROBOT_MOTORS_H
#define BALANCINGROBOT_MOTORS_H

#include <Arduino.h>
#include <Wire.h>


class Motors {
    int stepPin;
    int dirPin;
    int speed = 500;
    bool direction = false;

public:
    explicit Motors(int stepPin, int dirPin);

    void init() const;

    void step() const;

    void setSpeed(int newSpeed);

    void setDirection(bool forward);

};


#endif //BALANCINGROBOT_MOTORS_H
