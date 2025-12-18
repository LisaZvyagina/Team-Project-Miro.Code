#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>

std::string readFile(const std::string& filename);

void writeFile(const std::string& filename, const std::string& content);

#endif
