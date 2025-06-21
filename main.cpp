#include "sorts.h"
#include "utils.h"
#include "benchmarks.h"

#include <iostream>
#include <algorithm>

int main() {
    const std::string filename = "nums.txt";
    std::vector<int> original = readNumbersFromFile(filename);
    
    if (original.empty()) {
        std::cerr << "No data loaded from file. Exiting." << std::endl;
        return 1;
    }

    const int N = 160000;
    std::vector<int> data = getSubVector(original, N);

    std::cout << "Benchmarking sorting algorithms on " << data.size() << " elements\n" << std::endl;

    // Быстрая сортировка (с центром как опорным элементом)
    auto quickResult = runBenchmark("Quick Sort (center pivot)", data, 
        [](std::vector<int>& v) { return quick_sort(v, 0, v.size() - 1, false); });
    printBenchmark(quickResult);

    // Прямое слияние
    auto mergeResult = runBenchmark("Merge Sort", data, 
        [](std::vector<int>& v) { return merge_sort(v, 0, v.size() - 1); });
    printBenchmark(mergeResult);

    // Естественное слияние
    auto naturalMergeResult = runBenchmark("Natural Merge Sort", data, 
        [](std::vector<int>& v) { return natural_merge_sort(v, v.size()); });
    printBenchmark(naturalMergeResult);

    // Поразрядная сортировка
    auto radixResult = runBenchmark("Radix Sort", data, 
        [](std::vector<int>& v) { return radix_sort(v); });
    printBenchmark(radixResult);

    return 0;
}
