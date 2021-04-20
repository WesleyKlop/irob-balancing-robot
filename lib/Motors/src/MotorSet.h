#ifndef BALANCINGROBOT_MOTORSET_H
#define BALANCINGROBOT_MOTORSET_H

#include <Motor.h>

class MotorSet {
private:
    Motor motor1;
    Motor motor2;

public:
    MotorSet(uint8_t motor1StepPin, uint8_t motor1DirPin,
             uint8_t motor1Ms1Pin, uint8_t motor1Ms2Pin, uint8_t motor1Ms3Pin,
             uint8_t motor2StepPin, uint8_t motor2DirPin,
             uint8_t motor2Ms1Pin, uint8_t motor2Ms2Pin, uint8_t motor2Ms3Pin);

    void init();

    void setDirection(bool newDirection);

    void toggleStepState();
};


#endif //BALANCINGROBOT_MOTORSET_H
