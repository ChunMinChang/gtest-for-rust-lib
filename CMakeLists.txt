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

# Build tests
add_executable(test_sanity tests/test_sanity.cpp)
target_include_directories(test_sanity PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(test_sanity PRIVATE gtest_main)