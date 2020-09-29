#include <iostream>
#include <numeric>
#include <vector>

#include "InstrumentationTimer.h"
#include "Instrumentor.h"

double vector_accumulate(size_t n) {
    InstrumentationTimer timer("vector_accumulate");

    std::vector<int> v(n, 42);
    return std::accumulate(v.begin(), v.end(), 0u);
}

void run_benchmarks() {
    InstrumentationTimer timer("run_benchmarks");

    vector_accumulate(100);
    vector_accumulate(1000);
}

int main() {
    Instrumentor::get().beginSession("Profile");
    run_benchmarks();
    Instrumentor::get().endSession();
    return 1;
}