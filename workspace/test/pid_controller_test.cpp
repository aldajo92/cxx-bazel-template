#include "../main/PIDController.h"
#include <gtest/gtest.h>

TEST(PIDControllerTest, ComputeBasic)
{
    PIDController pid(1.0, 0.1, 0.05);

    double setpoint = 10.0;
    double process_value = 8.0;
    double control_signal = pid.compute(setpoint, process_value);

    // Check that the control signal is positive since the process value is less than the setpoint
    EXPECT_GT(control_signal, 0.0);
}

TEST(PIDControllerTest, ComputeSteadyState)
{
    PIDController pid(1.0, 0.1, 0.05);

    double setpoint = 10.0;
    double process_value = 10.0;
    double control_signal = pid.compute(setpoint, process_value);

    // At steady state, the control signal should ideally be 0
    EXPECT_NEAR(control_signal, 0.0, 1e-6);
}

TEST(PIDControllerTest, ResetIntegral)
{
    PIDController pid(1.0, 0.1, 0.05);

    double setpoint = 10.0;
    double process_value = 8.0;
    pid.compute(setpoint, process_value);

    // Reset the PID controller
    pid.reset();

    double control_signal = pid.compute(setpoint, process_value);

    // After resetting, the control signal should be computed without integral influence
    EXPECT_GT(control_signal, 0.0);
}
