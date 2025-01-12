#include "../main/hello_world.h"
#include <gtest/gtest.h>

TEST(HelloWorldTest, OutputTest) {
    // Since helloWorld outputs to stdout, you'd need to redirect stdout to test it properly.
    testing::internal::CaptureStdout();
    helloWorld();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!\n");
}
