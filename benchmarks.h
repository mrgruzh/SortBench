#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include <functional>

using SortResult = std::pair<int64_t, int64_t>;


using SortFunction = std::function<SortResult(std::vector<int>&)>;


struct BenchmarkResult {
    std::string name;
    int64_t timeMs;
    int64_t assignments;
    int64_t extraOps;
};


BenchmarkResult runBenchmark(const std::string& name,
                             std::vector<int> input,
                             SortFunction sortFn);


void printBenchmark(const BenchmarkResult& result);
