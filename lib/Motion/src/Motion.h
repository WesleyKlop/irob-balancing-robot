#ifndef BALANCINGROBOT_MOTION_H
#define BALANCINGROBOT_MOTION_H

#include <MPU9250_WE.h>

class Motion {
private:
    MPU9250_WE mpu9250;

    void calibrate();

public:
    explicit Motion(int addr);

    Motion();

    void init();

    xyzFloat getAngles();

    float getRoll();

    float getPitch();

    float getTemperature();

    xyzFloat getGyrValues();
};

#endif //BALANCINGROBOT_MOTION_H
