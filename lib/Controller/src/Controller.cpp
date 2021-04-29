#include "Controller.h"

Controller::Controller(double p, double i, double d)
        : pid(&input, &output, &setPoint, p, i, d, P_ON_E, DIRECT) {}


void Controller::init() {
    pid.SetOutputLimits(-200, 200);
    pid.SetSampleTime(10);
    pid.SetMode(AUTOMATIC);
}

inline void Controller::setInput(float newInput) {
    this->input = newInput;
}

inline bool Controller::compute() {
    return pid.Compute();
}

inline double Controller::read() const {
    return output;
}

inline double Controller::getInput() const {
    return input;
}

inline void Controller::tune(double p, double i, double d) {
    pid.SetTunings(p, i, d);
}
