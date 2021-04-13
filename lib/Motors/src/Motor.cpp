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

void Motor::setStepState(bool newState) const {
    digitalWrite(this->stepPin, newState);
}

void Motor::setSpeed(int newSpeed) {
    this->speed = newSpeed;
}

void Motor::setDirection(bool direction) const {
    digitalWrite(this->directionPin, this->invert == !direction);
}
