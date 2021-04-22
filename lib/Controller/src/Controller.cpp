//
// Created by Wesley Klop on 22/04/2021.
//

#include "Controller.h"

Controller::Controller(double p, double i, double d) : pid(&setPoint, &input, &output, p, i, d, P_ON_E, DIRECT) {}

void Controller::init() {
    pid.SetOutputLimits(-200, 200);
    pid.SetSampleTime(10);
    pid.SetMode(AUTOMATIC);
}

void Controller::setInput(float newInput) {
    this->input = newInput;
}

bool Controller::compute() {
   return pid.Compute();
}

double Controller::read() const {
    return output;
}
