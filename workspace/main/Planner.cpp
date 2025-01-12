#include "Planner.h"

// Constructor: Initialize with a reference to a Controller
Planner::Planner(Controller &controller)
    : controller_(controller) {}

// Method to plan and adjust based on the Controller
double Planner::plan(double setpoint, double current_value)
{
    return controller_.compute(setpoint, current_value);
}

// Method to reset the Controller
void Planner::reset()
{
    controller_.reset();
}
