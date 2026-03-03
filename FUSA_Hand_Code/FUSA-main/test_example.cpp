// test_example.cpp
#include <gtest/gtest.h>
#include "example.h" // Include the header file with the function declaration

// Define a test case
TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5); // Test add(2, 3) == 5
}

TEST(AdditionTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5); // Test add(-2, -3) == -5
}

TEST(AdditionTest, MixedNumbers) {
    EXPECT_EQ(add(2, -3), -1); // Test add(2, -3) == -1
}

/*
// Main function for running all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

