#pragma once

#include <chrono>

class InstrumentationTimer {
public:
    InstrumentationTimer(const char* name);
    ~InstrumentationTimer();

    void stop();

private:
    const char* name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint_;
    bool stopped_;
};