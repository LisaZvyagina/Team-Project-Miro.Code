#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>

// Чтение файла в строку
std::string readFile(const std::string &filename);

// Запись строки в файл
void writeFile(const std::string &filename, const std::string &content);

#endif
