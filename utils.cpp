#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<int> readNumbersFromFile(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return numbers;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }
    }

    file.close();
    return numbers;
}

std::vector<int> getSubVector(const std::vector<int>& original, int count) {
    if (count > original.size()) count = static_cast<int>(original.size());
    return std::vector<int>(original.begin(), original.begin() + count);
}

void printVector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}
