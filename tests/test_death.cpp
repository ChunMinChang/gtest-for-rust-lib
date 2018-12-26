#include <cassert>
#include "gtest/gtest.h"

#if defined(__cplusplus)
extern "C" {
#endif

// Call `assert!(false)`
extern void boom();

#if defined(__cplusplus)
}
#endif

void bang() { assert(false); }

TEST(gtest_rust, c_death) {
    ASSERT_DEATH(bang(), "");
}

// It's ok to call `bang()` twice.
TEST(gtest_rust, c_death_again) {
    ASSERT_DEATH(bang(), "");
}

TEST(gtest_rust, rust_death) {
    ASSERT_ANY_THROW(boom());
}

// This test will stop in the middle
// if `boom()` is called twice.
TEST(gtest_rust, rust_death_again) {
    ASSERT_ANY_THROW(boom());
}