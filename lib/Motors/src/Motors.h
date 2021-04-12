#ifndef BALANCINGROBOT_MOTORS_H
#define BALANCINGROBOT_MOTORS_H

#include <Arduino.h>
#include <Wire.h>


class Motors {
    int stepPin;
    int dirPin;

public:
    explicit Motors(int stepPin, int dirPin);

    void init() const;

    void test() const;
};


#endif //BALANCINGROBOT_MOTORS_H
