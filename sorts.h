#pragma once
#include <vector>
#include <cstdint>
#include <utility>

std::pair<int64_t, int64_t> find_max(const std::vector<int>& arr);
std::pair<int64_t, int64_t> counting_sort(std::vector<int>& arr, int exp);
std::pair<int64_t, int64_t> radix_sort(std::vector<int>& arr);

std::pair<int64_t, int64_t> merge(std::vector<int>& arr, int l, int m, int r);
std::pair<int64_t, int64_t> merge_sort(std::vector<int>& arr, int l, int r);
std::pair<int64_t, int64_t> natural_merge_sort(std::vector<int>& arr, int n);

std::pair<int64_t, int64_t> quick_sort(std::vector<int>& arr, int left, int right, bool flag);
