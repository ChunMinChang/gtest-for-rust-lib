#include "gtest/gtest.h"

TEST(rust_gtest, gtest_sanity) {
    ASSERT_EQ(4, 2 + 2);
}