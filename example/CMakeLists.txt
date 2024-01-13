cmake_minimum_required(VERSION 3.16)

project(example VERSION 1.2.3 LANGUAGES CXX)

# Enforce C++17 (required by Qt6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and setup Qt6
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

# Get all source files
file(GLOB_RECURSE SOURCES "main.cpp" "../src/*.cpp")

# Add the executable and link Qt6
qt_add_executable(example ${SOURCES})
target_link_libraries(example PRIVATE Qt6::Core)
