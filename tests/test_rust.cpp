#include "gtest/gtest.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern uint32_t cubic(uint32_t x);

#if defined(__cplusplus)
}
#endif

TEST(gtest_rust, rustlib) {
    ASSERT_EQ(cubic(2), 8);
}