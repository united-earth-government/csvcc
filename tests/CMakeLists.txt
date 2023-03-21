cmake_minimum_required(VERSION 3.20)

project(csvcc_unit_tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Adding multiple executable to the project
# Right-click on each item to set as start-up project

set(csvcc_proj_root "../")

# GoogleTest for basic implementation of function split_str()
add_executable(
    split_str_test
    "gtest_parse.cpp"
    "${csvcc_proj_root}/src/parse.hpp"
)


target_include_directories(split_str_test PRIVATE "${csvcc_proj_root}/src")

target_link_libraries(
    split_str_test
    GTest::gtest_main
)

include(GoogleTest)

# Make added executables discovered by GTest
gtest_discover_tests(
    split_str_test
)
