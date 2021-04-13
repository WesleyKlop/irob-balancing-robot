#include "Motor.h"

Motor::Motor(const uint8_t stepPin, const uint8_t dirPin) : Motor(stepPin, dirPin, false) {}

Motor::Motor(const uint8_t stepPin, const uint8_t dirPin, const bool invert) {
    this->stepPin = stepPin;
    this->directionPin = dirPin;
    this->invert = invert;
}

void Motor::init() const {
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->directionPin, OUTPUT);
    this->setDirection(HIGH);
}

void Motor::setStepState(bool newState) {
    this->currentStepState = newState;
    this->flushStepState();
}

void Motor::setDirection(bool direction) const {
    digitalWrite(this->directionPin, this->invert == !direction);
}

void Motor::toggleStepState() {
    this->currentStepState = !this->currentStepState;
    this->flushStepState();
}

void Motor::flushStepState() const {
    digitalWrite(this->stepPin, this->currentStepState);
}
