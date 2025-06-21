#include "benchmarks.h"
#include <chrono>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace std::chrono;

BenchmarkResult runBenchmark(const std::string& name,
                              std::vector<int> input,
                              SortFunction sortFn)
{
    BenchmarkResult result;
    result.name = name;

    auto start = steady_clock::now();
    auto res = sortFn(input);
    auto end = steady_clock::now();

    result.timeMs = duration_cast<milliseconds>(end - start).count();
    result.assignments = res.first;
    result.extraOps = res.second;

    return result;
}

void printBenchmark(const BenchmarkResult& result) {
    cout << "=== " << result.name << " ===" << endl;
    cout << "Time: " << result.timeMs << " ms" << endl;
    cout << "Assignments: " << result.assignments << endl;
    cout << "Extra Ops:   " << result.extraOps << endl;
    cout << endl;
}
