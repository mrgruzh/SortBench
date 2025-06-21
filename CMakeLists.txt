cmake_minimum_required(VERSION 3.10)
project(SortingBenchmark)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(SortingBenchmark
    main.cpp
    sorts.cpp
    utils.cpp
    benchmarks.cpp
)

target_include_directories(SortingBenchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
