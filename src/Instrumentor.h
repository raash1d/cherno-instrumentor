//
// Basic instrumentation profiler by Cherno

// Usage: include this header file somewhere in your code (eg. precompiled header), and then use
// like:
//
// Instrumentor::get().beginSession("Session Name");        // Begin session
// {
//     InstrumentationTimer timer("Profiled Scope Name");   // Place code like this in scopes you'd
//     like to include in profiling
//     // Code
// }
// Instrumentor::get().endSession();                        // End Session
//
// You will probably want to macro-fy this, to switch on/off easily and use things like __FUNCSIG__
// for the profile name.
//
#pragma once

#include <algorithm>
#include <fstream>
#include <string>

struct ProfileResult {
    std::string name;
    long long start, end;
    uint32_t threadID;
};

struct InstrumentationSession {
    std::string name;
};

class Instrumentor {
public:
    void beginSession(const std::string& name, const std::string& filepath);
    void endSession();

    void writeProfile(const ProfileResult& result);
    void writeHeader();
    void writeFooter();

    static Instrumentor& get();

private:
    InstrumentationSession* currentSession_{nullptr};
    std::ofstream outputStream_;
    int profileCount_{0};
};
