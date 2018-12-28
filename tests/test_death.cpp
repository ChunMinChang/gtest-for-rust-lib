#include <cassert>
#include <csignal>
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

void panic() { throw SIGILL; }

// Hitting a C assertion twice
// ----------------------------------------------------------------------------
TEST(gtest_rust, c_death) {
    ASSERT_DEATH(bang(), "");
}

TEST(gtest_rust, c_death_again) {
    ASSERT_DEATH(bang(), "");
}

// Catching a C exception twice
// ----------------------------------------------------------------------------
TEST(gtest_rust, c_throw_an_exception) {
    ASSERT_ANY_THROW(panic());
}

TEST(gtest_rust, c_throw_an_exception_again) {
    ASSERT_ANY_THROW(panic());
}

// Hitting a Rust assertion twice
// This is not possible! See
// https://users.rust-lang.org/t/how-to-write-a-death-test-in-gtest-for-rust-apis/
// ----------------------------------------------------------------------------
// TEST(gtest_rust, rust_death) {
//     ASSERT_ANY_THROW(boom());
// }

// // This test will stop in the middle when `boom()` is called again!
// TEST(gtest_rust, rust_death_again) {
//     ASSERT_ANY_THROW(boom());
// }