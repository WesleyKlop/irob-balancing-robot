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

void Motors::step() const {
    digitalWrite(this->stepPin, HIGH);
    delayMicroseconds(this->speed);
    digitalWrite(this->stepPin, LOW);
    delayMicroseconds(this->speed);
}

void Motors::setSpeed(int newSpeed) {
    this->speed = newSpeed;
}

void Motors::setDirection(bool direction) {
    digitalWrite(this->directionPin, direction);
}