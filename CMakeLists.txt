cmake_minimum_required(VERSION 3.10)

project(rust_gtest)

# Set standards of C and C++
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup for GTest
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/googletest/CMakeLists.txt")
    message(FATAL_ERROR "Could not find googletest: run\n\tgit submodule update --init --recursive\nin base git checkout")
endif()

add_subdirectory(googletest)

# Build external library
include(ExternalProject)
ExternalProject_Add(
    rslib
    DOWNLOAD_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND rustc --crate-type=staticlib demo.rs
    BINARY_DIR "${PROJECT_SOURCE_DIR}/rustlib"
    INSTALL_COMMAND ""
    LOG_BUILD ON
)

# Build tests
add_executable(test_sanity tests/test_sanity.cpp)
target_include_directories(test_sanity PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(test_sanity PRIVATE gtest_main)

add_executable(test_rust tests/test_rust.cpp)
add_dependencies(test_rust rslib)
target_include_directories(test_rust PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(test_rust PRIVATE
    debug "${PROJECT_SOURCE_DIR}/rustlib/libdemo.a"
    optimized "${PROJECT_SOURCE_DIR}/rustlib/libdemo.a"
    gtest_main
)

add_executable(test_death tests/test_death.cpp)
add_dependencies(test_death rslib)
target_include_directories(test_death PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(test_death PRIVATE
    debug "${PROJECT_SOURCE_DIR}/rustlib/libdemo.a"
    optimized "${PROJECT_SOURCE_DIR}/rustlib/libdemo.a"
    gtest_main
)