#include "Instrumentor.h"

void Instrumentor::beginSession(const std::string& name,
                                const std::string& filepath = "results.json") {
    outputStream_.open(filepath);
    writeHeader();
    currentSession_ = new InstrumentationSession{name};
}

void Instrumentor::endSession() {
    writeFooter();
    outputStream_.close();
    delete currentSession_;
    currentSession_ = nullptr;
    profileCount_ = 0;
}

void Instrumentor::writeProfile(const ProfileResult& result) {
    if (profileCount_++ > 0) {
        outputStream_ << ",";
    }

    std::string name = result.name;
    std::replace(name.begin(), name.end(), '"', '\'');

    outputStream_ << "{";
    outputStream_ << "\"cat\":\"function\",";
    outputStream_ << "\"dur\":" << (result.end - result.start) << ',';
    outputStream_ << "\"name\":\"" << name << "\",";
    outputStream_ << "\"ph\":\"X\",";
    outputStream_ << "\"pid\":0,";
    outputStream_ << "\"tid\":" << result.threadID << ",";
    outputStream_ << "\"ts\":" << result.start;
    outputStream_ << "}";

    outputStream_.flush();
}

void Instrumentor::writeHeader() {
    outputStream_ << "{\"otherData\": {},\"traceEvents\":[";
    outputStream_.flush();
}

void Instrumentor::writeFooter() {
    outputStream_ << "]}";
    outputStream_.flush();
}

Instrumentor& Instrumentor::get() {
    static Instrumentor instance;
    return instance;
}
