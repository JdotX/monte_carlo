cmake_minimum_required(VERSION 3.10)

project(monte_carlo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-stdlib=libc++")

include_directories(common benchmarks)
add_subdirectory(benchmarks)
add_executable(monte_carlo common/main.cpp)
target_link_libraries(monte_carlo PUBLIC RNGBenchmark)


