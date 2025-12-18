#include "file_io.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string readFile(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения: " << filename << std::endl;
        return "";
    }
    std::ostringstream oss;
    oss << file.rdbuf();
    return oss.str();
}

void writeFile(const std::string &filename, const std::string &content) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << filename << std::endl;
        return;
    }
    file << content;
    std::cout << "Файл успешно записан: " << filename << std::endl;
}