cmake_minimum_required(VERSION 3.0.0)
project(Sample
        VERSION 0.0.1
        DESCRIPTION "Instrumentor sample"
        LANGUAGES CXX)

add_executable(instrumentor_sample
        instrumentor_sample.cpp)

# target_compile_features(instrumentor
#     PRIVATE
#     cxx_std_17)

target_include_directories(instrumentor_sample
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(instrumentor_sample
        instrumentor
)

if (ENABLE_PROFILING)
    target_compile_definitions(instrumentor_sample
        PRIVATE
        ENABLE_PROFILING=1)
endif()
