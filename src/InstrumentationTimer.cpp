#include "InstrumentationTimer.h"

#include <thread>

#include "Instrumentor.h"

InstrumentationTimer::InstrumentationTimer(const char* name)
    : name_(name)
    , startTimepoint_(std::chrono::high_resolution_clock::now())
    , stopped_(false) {
}

InstrumentationTimer::~InstrumentationTimer() {
    if (!stopped_) {
        stop();
    }
}

void InstrumentationTimer::stop() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    long long const start{std::chrono::time_point_cast<std::chrono::microseconds>(startTimepoint_)
                              .time_since_epoch()
                              .count()};
    long long const end{std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint)
                            .time_since_epoch()
                            .count()};

    uint32_t const threadID{
        static_cast<uint32_t>(std::hash<std::thread::id>{}(std::this_thread::get_id()))};
    Instrumentor::get().writeProfile({name_, start, end, threadID});

    stopped_ = true;
}