#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "Controller.h"
#include <chrono>

class PIDController : public Controller
{
private:
    // PID gains
    double kp_; // Proportional gain
    double ki_; // Integral gain
    double kd_; // Derivative gain

    // Internal state
    double previous_error_;
    double integral_;
    std::chrono::steady_clock::time_point last_time_;

public:
    // Constructor
    PIDController(double kp, double ki, double kd);

    // Override methods from the Controller interface
    double compute(double setpoint, double current_value) override;
    void reset() override;

    // Setters for PID gains
    void setKp(double kp);
    void setKi(double ki);
    void setKd(double kd);

    // Getters for PID gains
    double getKp() const;
    double getKi() const;
    double getKd() const;

    // Destructor
    ~PIDController() override = default;
};

#endif // PIDCONTROLLER_H
