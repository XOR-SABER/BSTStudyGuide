#include <gtest/gtest.h>
#include <math.h>

TEST(DefaultSuite, basicTest) {
    EXPECT_EQ(std::sqrt(4), 2);
}