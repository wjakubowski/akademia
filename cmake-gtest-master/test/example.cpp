#include "gtest/gtest.h"
#include "example.hpp"


TEST(ExampleTest, DISABLED_StringComparisonWorks) {
  EXPECT_STREQ("Ala", "Ala");
  EXPECT_STRNE("Ala", "kot");
}

TEST(ExampleTest, DISABLED_BrokenTest) {
    const char* text = "Ala";
    char buf[sizeof(text)];
    strcpy(buf, text);
    EXPECT_EQ(text, buf);
}

TEST(ExampleTest, DISABLED_FiveReturnsFive) {
    EXPECT_EQ(five(), 5);
}

TEST(RootsTest, PositiveDelta)
{
    Solution s = roots(1, -3, 2);
    ASSERT_EQ(s.count,2);
    double eps = 1e-5;
    EXPECT_NEAR(s.x1,1,eps);
    EXPECT_NEAR(s.x2,2,eps);
    EXPECT_DOUBLE_EQ(s.x1,1);
    EXPECT_DOUBLE_EQ(s.x2,2);
    EXPECT_TRUE(s.x1 == 1.0 && s.x2 == 2.0 || s.x1 == 2.0 && s.x2 == 1.0);
    EXPECT_FALSE(s.identity);
}

TEST(RootsTest, ZeroDelta)
{
    Solution s = roots(1, -2, 1);
    ASSERT_EQ(s.count,1);
    double eps = 1e-5;
    EXPECT_NEAR(s.x1,1,eps);
    EXPECT_NEAR(s.x2,1,eps);
    EXPECT_DOUBLE_EQ(s.x1,1);
    EXPECT_DOUBLE_EQ(s.x2,1);
    EXPECT_TRUE(s.x1 == 1.0 && s.x2 == 1.0);
    EXPECT_FALSE(s.identity);
}

TEST(RootsTest, IdentyfyEqation)
{
    Solution s = roots(0, 0, 0);
    EXPECT_TRUE(s.identity);
}
