cmake_minimum_required(VERSION 3.20)

project(csvcc_examples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file("example_file.csv" "example_file.csv" COPYONLY)

set(csvcc_proj_root "../")

add_executable(
    basic_usage
    "basic_usage.cpp"
    "${csvcc_proj_root}/src/csvfile.hpp"
    "${csvcc_proj_root}/src/csvrow.hpp"
    "example_file.csv"
)

target_include_directories(basic_usage PRIVATE "${csvcc_proj_root}/src")
