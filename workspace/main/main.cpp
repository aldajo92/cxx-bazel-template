// main/main.cpp
#include <iostream>
#include <chrono>
#include <thread>
#include "Planner.h"
#include "PIDController.h"

int main()
{
    // Create a PIDController instance with gains
    PIDController pid(1.0, 0.1, 0.05);

    // Create a Planner instance, passing the PIDController
    Planner planner(pid);

    // Define the setpoint and initial process value
    double setpoint = 100.0;     // Desired target value
    double process_value = 50.0; // Initial value of the system

    // Timing setup
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::seconds(10); // 10-second duration

    // Simulate a control loop
    while (std::chrono::steady_clock::now() < end_time)
    {
        // Compute the control signal using the planner
        double control_signal = planner.plan(setpoint, process_value);

        // Simulate the system's response to the control signal
        process_value += control_signal * 0.1;

        // Print the current state
        std::cout << "Time: "
                  << std::chrono::duration_cast<std::chrono::seconds>(
                         std::chrono::steady_clock::now() - start_time)
                         .count()
                  << "s, Process Value: " << process_value
                  << ", Control Signal: " << control_signal << std::endl;

        // Sleep for a short duration to simulate a control loop interval (e.g., 500ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Control loop ended after 10 seconds." << std::endl;

    return 0;
}
