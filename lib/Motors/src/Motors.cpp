#include "Motors.h"

Motors::Motors(const int stepPin, const int dirPin) {
    this->stepPin = stepPin;
    this->dirPin = dirPin;

};

void Motors::init() const {
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->dirPin, OUTPUT);
    digitalWrite(this->dirPin, HIGH);
}

void Motors::test() const {
    digitalWrite(this->stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(this->stepPin, LOW);
    delayMicroseconds(500);
}
