#include "../main/Planner.h"
#include "../main/Controller.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Mock class for Controller
class MockController : public Controller
{
public:
    MOCK_METHOD(double, compute, (double setpoint, double current_value), (override));
    MOCK_METHOD(void, reset, (), (override));
};

// Test case for Planner::plan
TEST(PlannerTest, PlanMethodCallsCompute)
{
    MockController mock_controller;
    Planner planner(mock_controller);

    double setpoint = 100.0;
    double process_value = 50.0;
    double expected_control_signal = 25.0;

    EXPECT_CALL(mock_controller, compute(setpoint, process_value))
        .Times(1)
        .WillOnce(::testing::Return(expected_control_signal));

    double control_signal = planner.plan(setpoint, process_value);

    EXPECT_DOUBLE_EQ(control_signal, expected_control_signal);
}

// Test case for Planner::reset
TEST(PlannerTest, ResetMethodCallsReset)
{
    MockController mock_controller;
    Planner planner(mock_controller);

    EXPECT_CALL(mock_controller, reset())
        .Times(1);

    planner.reset();
}
