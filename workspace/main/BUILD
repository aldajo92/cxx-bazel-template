cc_library(
    name = "controller_lib",
    hdrs = ["Controller.h"],  # Header file for the Controller interface
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pid_controller_lib",
    srcs = ["PIDController.cpp"],
    hdrs = ["PIDController.h", "Controller.h"],  # Include Controller.h for dependency
    deps = [":controller_lib"],  # Depend on Controller library
    visibility = ["//visibility:public"],
)

cc_library(
    name = "planner_lib",
    srcs = ["Planner.cpp"],
    hdrs = ["Planner.h"],
    deps = [":pid_controller_lib"],  # Depend on the PIDController library
    visibility = ["//visibility:public"],
)

cc_library(
    name = "hello_world_lib",
    srcs = ["hello_world.cpp"],
    hdrs = ["hello_world.h"],
    deps = [":pid_controller_lib"],  # Depend on the PID controller library
    visibility = ["//visibility:public"],  # Make the target visible to all packages
)

cc_library(
    name = "main_lib",
    srcs = ["main.cpp"],
    deps = [":hello_world_lib", ":pid_controller_lib", ":planner_lib"],  # Add PID dependency here
    visibility = ["//visibility:public"],  # Make the target visible to all packages
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cpp"],
    deps = [":main_lib", ":pid_controller_lib", ":planner_lib"],  # Binary depends on main_lib and PID
)
