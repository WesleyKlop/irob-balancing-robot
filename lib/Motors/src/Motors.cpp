#include "Motors.h"

Motors::Motors(const int stepPin, const int dirPin) {
    this->stepPin = stepPin;
    this->directionPin = dirPin;
};

void Motors::init() const {
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->directionPin, OUTPUT);
    digitalWrite(this->directionPin, HIGH);
}

void Motors::setStepState(bool newState) const {
    digitalWrite(this->stepPin, newState);
}

void Motors::setSpeed(int newSpeed) {
    this->speed = newSpeed;
}

void Motors::setDirection(bool direction) const {
    digitalWrite(this->directionPin, direction);
}