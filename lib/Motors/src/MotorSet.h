#ifndef BALANCINGROBOT_MOTORSET_H
#define BALANCINGROBOT_MOTORSET_H

#include <Motor.h>

class MotorSet {
private:
    Motor motor1;
    Motor motor2;

public:
    MotorSet(uint8_t motor1StepPin, uint8_t motor1DirPin,
             uint8_t motor2StepPin, uint8_t motor2DirPin);

    void init();

    void setStepState(bool newState);
};


#endif //BALANCINGROBOT_MOTORSET_H
