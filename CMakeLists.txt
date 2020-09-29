cmake_minimum_required(VERSION 3.0.0)
project(Instrumentor
    VERSION 0.0.1
    DESCRIPTION "Instrumentation engine"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -Wextra") # $ENV{EXTRA_CFLAGS}")
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -Wextra") # $ENV{EXTRA_CFLAGS}")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE debug CACHE STRING "" FORCE)
endif()

if (PROFILING)
    message(STATUS "Profiling enabled")
    add_definitions(-DENABLE_PROFILING=1)
else()
    message(STATUS "Profiling disabled")
    add_definitions(-DENABLE_PROFILING=0)
endif()

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(sample)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
