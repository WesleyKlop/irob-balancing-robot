//
// Created by Wesley Klop on 08/04/2021.
//
#include <MPU9250_WE.h>
#include <Wire.h>

#ifndef BALANCINGROBOT_MOTION_H
#define BALANCINGROBOT_MOTION_H

class Motion {
    MPU9250_WE mpu9250;
private:
    void calibrate();

public:
    explicit Motion(int addr);

    void init();

    xyzFloat getAngles();
    float getRoll();
    float getPitch();
    float getTemperature();
};

#endif //BALANCINGROBOT_MOTION_H
