#include "Motor.h"

Motor::Motor(const uint8_t stepPin, const uint8_t dirPin, uint8_t ms1Pin, uint8_t ms2Pin, uint8_t ms3Pin) : Motor(
        stepPin, dirPin, ms1Pin, ms2Pin, ms3Pin, false) {}

Motor::Motor(const uint8_t stepPin, const uint8_t dirPin, uint8_t ms1Pin, uint8_t ms2Pin, uint8_t ms3Pin,
             const bool invert) {
    this->stepPin = stepPin;
    this->directionPin = dirPin;
    this->invert = invert;
    this->ms1Pin = ms1Pin;
    this->ms2Pin = ms2Pin;
    this->ms3Pin = ms3Pin;
}

void Motor::init(StepResolution resolution) {
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->directionPin, OUTPUT);
    pinMode(this->ms1Pin, OUTPUT);
    pinMode(this->ms1Pin, OUTPUT);
    pinMode(this->ms2Pin, OUTPUT);
    pinMode(this->ms3Pin, OUTPUT);

    this->setDirection(HIGH);
    this->setResolution(resolution);
}

void Motor::setResolution(StepResolution resolution) {
    if (this->currentResolution == resolution) {
        return;
    }
    this->currentResolution = resolution;
    this->flushResolution();
}

void Motor::setDirection(bool direction) {
    if(this->currentDirection == direction) {
        return;
    }
    this->currentDirection = direction;
    this->flushDirection();
}

void Motor::toggleStepState() {
    this->currentStepState = !this->currentStepState;
    this->flushStepState();
}

inline void Motor::flushStepState() const {
    digitalWrite(this->stepPin, this->currentStepState);
}

inline void Motor::flushResolution() const {
    switch (this->currentResolution) {
        case FULL:
            digitalWrite(this->ms1Pin, LOW);
            digitalWrite(this->ms2Pin, LOW);
            digitalWrite(this->ms3Pin, LOW);
            return;
        case HALF:
            digitalWrite(this->ms1Pin, HIGH);
            digitalWrite(this->ms2Pin, LOW);
            digitalWrite(this->ms3Pin, LOW);
            return;
        case QUARTER:
            digitalWrite(this->ms1Pin, LOW);
            digitalWrite(this->ms2Pin, HIGH);
            digitalWrite(this->ms3Pin, LOW);
            return;
        case EIGHTH:
            digitalWrite(this->ms1Pin, HIGH);
            digitalWrite(this->ms2Pin, HIGH);
            digitalWrite(this->ms3Pin, LOW);
            return;
        case SIXTEENTH:
            digitalWrite(this->ms1Pin, HIGH);
            digitalWrite(this->ms2Pin, HIGH);
            digitalWrite(this->ms3Pin, HIGH);
            return;
    }
}

inline void Motor::flushDirection() const {
    digitalWrite(this->directionPin, this->invert == !this->currentDirection);
}
