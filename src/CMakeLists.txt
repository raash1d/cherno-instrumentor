add_library(instrumentor
    SHARED
    Instrumentor.cpp
    InstrumentationTimer.cpp)

# target_compile_features(instrumentor
#     PRIVATE
#     cxx_std_17)