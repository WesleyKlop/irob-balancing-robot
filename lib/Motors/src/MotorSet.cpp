#include "MotorSet.h"

MotorSet::MotorSet(
        const uint8_t motor1StepPin, const uint8_t motor1DirPin,
        const uint8_t motor2StepPin, const uint8_t motor2DirPin)
        : motor1(motor1StepPin, motor1DirPin, true), motor2(motor2StepPin, motor2DirPin) {}

void MotorSet::init() {
    this->motor1.init();
    this->motor2.init();
}

void MotorSet::setStepState(bool newState) {
    this->motor1.setStepState(newState);
    this->motor2.setStepState(newState);
}

void MotorSet::setDirection(bool newDirection) {
    this->motor1.setDirection(newDirection);
    this->motor2.setDirection(newDirection);
}

void MotorSet::toggleStepState() {
    this->motor1.toggleStepState();
    this->motor2.toggleStepState();
}
