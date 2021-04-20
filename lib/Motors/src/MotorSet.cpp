#include "MotorSet.h"

MotorSet::MotorSet(
        const uint8_t motor1StepPin, const uint8_t motor1DirPin,
        const uint8_t motor1Ms1Pin, const uint8_t motor1Ms2Pin, const uint8_t motor1Ms3Pin,
        const uint8_t motor2StepPin, const uint8_t motor2DirPin,
        const uint8_t motor2Ms1Pin, const uint8_t motor2Ms2Pin, const uint8_t motor2Ms3Pin
) :
motor1(motor1StepPin, motor1DirPin, motor1Ms1Pin, motor1Ms2Pin, motor1Ms3Pin, true),
motor2(motor2StepPin, motor2DirPin, motor2Ms1Pin, motor2Ms2Pin, motor2Ms3Pin, true) {}

void MotorSet::init() {
    this->motor1.init();
    this->motor2.init();
}

void MotorSet::setDirection(bool newDirection) {
    this->motor1.setDirection(newDirection);
    this->motor2.setDirection(newDirection);
}

void MotorSet::toggleStepState() {
    this->motor1.toggleStepState();
    this->motor2.toggleStepState();
}
