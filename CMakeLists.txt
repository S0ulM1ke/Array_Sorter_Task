cmake_minimum_required(VERSION 3.20)

# Project name
project(ArraySorterTask VERSION 0.1.0
        DESCRIPTION "Array sorting test task"
        LANGUAGES CXX)


# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_LICENSE "GPL-3.0-only")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

# Add source files
set(PROJECT_SOURCES
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/commandlineparser.h"
    "${CMAKE_SOURCE_DIR}/src/commandlineparser.cpp"
    #src/ArraySorter.cpp
)

# Add include directories
include_directories(include)

# Create executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Add any required libraries (if needed)
# target_link_libraries(${PROJECT_NAME} <library_name>)