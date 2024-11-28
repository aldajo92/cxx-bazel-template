#ifndef PLANNER_H
#define PLANNER_H

#include "Controller.h"

class Planner
{
private:
    Controller &controller_; // Dependency on the Controller interface

public:
    // Constructor: accepts a Controller instance
    Planner(Controller &controller);

    // Method to plan and adjust based on the controller
    double plan(double setpoint, double current_value);

    // Method to reset the controller
    void reset();
};

#endif // PLANNER_H
