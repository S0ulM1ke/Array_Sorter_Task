cmake_minimum_required(VERSION 3.20)

# Project name
project(ArraySorterTask VERSION 0.1.0
        DESCRIPTION "Array sorting test task"
        HOMEPAGE_URL "https://github.com/S0ulM1ke"
        LANGUAGES CXX)


# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

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
    "${CMAKE_SOURCE_DIR}/src/utility.h"
    "${CMAKE_SOURCE_DIR}/src/arraytransformer.h"
    "${CMAKE_SOURCE_DIR}/src/sortedarray.h"
    "${CMAKE_SOURCE_DIR}/src/intersectarray.h"
    "${CMAKE_SOURCE_DIR}/src/uniquerevarray.h"
)

# Add include directories
include_directories(include)

# Create executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Add any required libraries (if needed)
# target_link_libraries(${PROJECT_NAME} <library_name>)