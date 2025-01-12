#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    // Abstract method to compute the control output
    virtual double compute(double setpoint, double current_value) = 0;

    // Abstract method to reset the controller state
    virtual void reset() = 0;

    // Virtual destructor for cleanup
    virtual ~Controller() = default;
};

#endif // CONTROLLER_H
