#pragma once
#include <vector>
#include <string>
// Чтение чисел из текстового файла
std::vector<int> readNumbersFromFile(const std::string& filename);
// Получение первых N элементов из вектора
std::vector<int> getSubVector(const std::vector<int>& original, int count);
// Печать вектора в stdout
void printVector(const std::vector<int>& vec);
