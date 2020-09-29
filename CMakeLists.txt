cmake_minimum_required(VERSION 3.0.0)
project(Instrumentor VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -Wextra") # $ENV{EXTRA_CFLAGS}")
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -Wextra") # $ENV{EXTRA_CFLAGS}")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE debug CACHE STRING "" FORCE)
endif()

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(sample)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
