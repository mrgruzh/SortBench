#include "sorts.h"
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// ======= Radix Sort =======

pair<int64_t, int64_t> find_max(const vector<int>& arr) {
    pair<int64_t, int64_t> max{arr[0], 0};
    for (size_t i = 1; i < arr.size(); ++i, max.second++) {
        if (arr[i] > max.first) {
            max.first = arr[i];
            max.second++;
        }
    }
    return max;
}

pair<int64_t, int64_t> counting_sort(vector<int>& arr, int exp) {
    pair<int64_t, int64_t> assignments{0, 0};
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    for (int i : arr) {
        count[(i / exp) % 10]++;
        assignments.second++;
    }

    for (int i = 1; i < 10; ++i, assignments.second++) {
        count[i] += count[i - 1];
        assignments.second++;
    }

    for (int i = arr.size() - 1; i >= 0; --i, assignments.second++) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        ++assignments.first;
        count[(arr[i] / exp) % 10]--;
        assignments.second++;
    }

    arr = output;
    assignments.second++;
    return assignments;
}

pair<int64_t, int64_t> radix_sort(vector<int>& arr) {
    pair<int64_t, int64_t> assignments{0, 0};
    auto max = find_max(arr);
    assignments.second += max.second;

    for (int exp = 1; max.first / exp > 0; exp *= 10, assignments.second++) {
        auto tmp = counting_sort(arr, exp);
        assignments.first += tmp.first;
        assignments.second += tmp.second;
    }

    return assignments;
}

// ======= Merge Sort =======

pair<int64_t, int64_t> merge(vector<int>& arr, int l, int m, int r) {
    pair<int64_t, int64_t> assignments{0, 0};

    int n1 = m - l + 1;
    int n2 = r - m;
    assignments.second += 2;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i, assignments.second++) {
        L[i] = arr[l + i];
        assignments.second++;
    }
    for (int j = 0; j < n2; ++j, assignments.second++) {
        R[j] = arr[m + 1 + j];
        assignments.second++;
    }

    int i = 0, j = 0, k = l;
    assignments.second += 3;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        ++assignments.first;
        assignments.second += 3;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        ++assignments.first;
        assignments.second += 2;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        ++assignments.first;
        assignments.second += 2;
    }

    return assignments;
}

pair<int64_t, int64_t> merge_sort(vector<int>& arr, int l, int r) {
    pair<int64_t, int64_t> assignments{0, 0};

    if (l < r) {
        int m = l + (r - l) / 2;
        assignments.second++;

        auto left = merge_sort(arr, l, m);
        auto right = merge_sort(arr, m + 1, r);
        auto merged = merge(arr, l, m, r);

        assignments.first = left.first + right.first + merged.first;
        assignments.second += left.second + right.second + merged.second;
    }

    return assignments;
}

// ======= Natural Merge Sort =======

pair<int64_t, int64_t> natural_merge_sort(vector<int>& arr, int n) {
    pair<int64_t, int64_t> assignments{0, 0};
    if (n <= 1) return assignments;

    bool sorted = false;
    assignments.second++;

    while (!sorted) {
        sorted = true;
        assignments.second++;

        int l = 0;
        assignments.second++;

        while (l < n) {
            int m = l;
            assignments.second++;

            while (m + 1 < n && arr[m] <= arr[m + 1]) {
                ++m;
                assignments.second++;
            }

            if (m + 1 < n) {
                int r = m + 1;
                assignments.second++;

                while (r + 1 < n && arr[r] <= arr[r + 1]) {
                    ++r;
                    assignments.second++;
                }

                auto tmp = merge(arr, l, m, r);
                assignments.first += tmp.first;
                assignments.second += tmp.second;

                sorted = false;
                l = r + 1;
                assignments.second += 2;
            } else {
                l = n;
                assignments.second++;
            }
        }
    }

    return assignments;
}

// ======= Quick Sort =======

pair<int64_t, int64_t> quick_sort(vector<int>& arr, int left, int right, bool flag) {
    pair<int64_t, int64_t> assignments{0, 0};
    if (left >= right) return assignments;

    int i = left, j = right;
    assignments.second += 2;

    int center = flag ? arr[j] : arr[(i + j) / 2];
    assignments.second++;

    while (j >= i) {
        while (arr[i] < center) {
            ++i;
            assignments.second++;
        }
        while (arr[j] > center) {
            --j;
            assignments.second++;
        }

        if (j >= i) {
            swap(arr[i], arr[j]);
            assignments.first += 2;
            assignments.second += 2;
            ++i; --j;
            assignments.second += 2;
        }
    }

    auto left_result = quick_sort(arr, left, j, flag);
    auto right_result = quick_sort(arr, i, right, flag);

    assignments.first += left_result.first + right_result.first;
    assignments.second += left_result.second + right_result.second;

    return assignments;
}
