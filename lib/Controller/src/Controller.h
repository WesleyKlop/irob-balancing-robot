//
// Created by Wesley Klop on 22/04/2021.
//

#ifndef BALANCINGROBOT_CONTROLLER_H
#define BALANCINGROBOT_CONTROLLER_H

#include <PID_v1.h>

class Controller {
private:

    PID pid;
    double setPoint = 0;
    double input = 0;
    double output = 0;

public:
    Controller(double p, double i, double d);

    void init();

    void setInput(float input);

    bool compute();

    double read() const;

    double getInput() const;
};


#endif //BALANCINGROBOT_CONTROLLER_H
