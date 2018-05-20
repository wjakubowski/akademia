#include "gtest/gtest.h"
#include "example.hpp"
#include <cmath>

#include <cassert>

TEST(RootsTest, PositiveDelta) {
    Solution s = roots(1, -3, 2);
    ASSERT_EQ(s.count, 2);

    double x1 = std::min(s.x1, s.x2);
    double x2 = std::max(s.x1, s.x2);

    const double eps = 1e-5;
    EXPECT_NEAR(x1, 1.0, eps);
    EXPECT_NEAR(x2, 2.0, eps);

    EXPECT_DOUBLE_EQ(x1, 1.0);
    EXPECT_DOUBLE_EQ(x2, 2.0);

    EXPECT_FALSE(s.identity);
}
