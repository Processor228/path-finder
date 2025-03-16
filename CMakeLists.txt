cmake_minimum_required(VERSION 3.15)
project(PathFinder)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/fetch-cli11.cmake)
include(cmake/fetch-gtest.cmake)
include(cmake/development-instruments.cmake)

add_subdirectory(src)
add_subdirectory(tests)