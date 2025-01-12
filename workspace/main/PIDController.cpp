#include "PIDController.h"

// Constructor
PIDController::PIDController(double kp, double ki, double kd)
    : kp_(kp), ki_(ki), kd_(kd), previous_error_(0.0), integral_(0.0),
      last_time_(std::chrono::steady_clock::now()) {}

// Method to compute the control output
double PIDController::compute(double setpoint, double current_value)
{
    // Calculate error
    double error = setpoint - current_value;

    // Get the current time and calculate elapsed time (dt)
    auto current_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = current_time - last_time_;
    double dt = elapsed.count();

    if (dt > 0.0)
    {
        // Proportional term
        double proportional = kp_ * error;

        // Integral term
        integral_ += error * dt;
        double integral = ki_ * integral_;

        // Derivative term
        double derivative = kd_ * (error - previous_error_) / dt;

        // Save current error and time for next calculation
        previous_error_ = error;
        last_time_ = current_time;

        // Return total control output
        return proportional + integral + derivative;
    }
    else
    {
        // If no time has passed, return 0 to avoid division by zero
        return 0.0;
    }
}

// Reset the integral and previous error terms
void PIDController::reset()
{
    integral_ = 0.0;
    previous_error_ = 0.0;
    last_time_ = std::chrono::steady_clock::now();
}

// Setters for PID gains
void PIDController::setKp(double kp) { kp_ = kp; }
void PIDController::setKi(double ki) { ki_ = ki; }
void PIDController::setKd(double kd) { kd_ = kd; }

// Getters for PID gains
double PIDController::getKp() const { return kp_; }
double PIDController::getKi() const { return ki_; }
double PIDController::getKd() const { return kd_; }
