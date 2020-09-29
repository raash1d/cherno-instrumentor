cmake_minimum_required(VERSION 3.0.0)
project(Sample VERSION 0.0.1)

add_executable(instrumentor_sample
        instrumentor_sample.cpp)

target_include_directories(instrumentor_sample
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(
        instrumentor
)