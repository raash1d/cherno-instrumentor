#include <iostream>
#include <numeric>
#include <vector>

#include "InstrumentorConfig.h"

double vector_accumulate(size_t n, int i) {
    PROFILE_FUNCTION();

    std::vector<int> v(n, i);
    return std::accumulate(v.begin(), v.end(), 0u);
}

double vector_accumulate(size_t n) {
    PROFILE_FUNCTION();

    std::vector<int> v(n, 42);
    return std::accumulate(v.begin(), v.end(), 0u);
}

void run_benchmarks() {
    PROFILE_FUNCTION();

    std::cout << "Running benchmarks...\n";
    vector_accumulate(100);
    vector_accumulate(100, 33);
}

int main() {
    PROFILE_BEGIN_SESSION("InstrumentorSampleProfile", "InstrumentorSampleProfile.json");
    run_benchmarks();
    PROFILE_END_SESSION();
    return 1;
}