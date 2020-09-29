#pragma once

#include "InstrumentationTimer.h"
#include "Instrumentor.h"

#if ENABLE_PROFILING
    #define PROFILE_BEGIN_SESSION(name, filepath) Instrumentor::get().beginSession(name, filepath)
    #define PROFILE_END_SESSION() Instrumentor::get().endSession()
    #define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
    #if _MSC_VER
        #define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
    #elif __clang__ || __GNUC__
        #define PROFILE_FUNCTION() PROFILE_SCOPE(__PRETTY_FUNCTION__)
    #endif
#else
    #define PROFILE_BEGIN_SESSION(name, filepath)
    #define PROFILE_END_SESSION()
    #define PROFILE_SCOPE(name)
    #define PROFILE_FUNCTION()
#endif