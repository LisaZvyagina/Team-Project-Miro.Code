// base64_decode.cpp
#include "base64_decode.h"
#include <string>
#include <vector>
#include <cstdint>

const std::string BASE64_ALPHABET =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Функция для поиска индекса символа в алфавите Base64
int find_base64_index(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    if (c == '=') return -1; // символ padding
    return -2; // невалидный символ
}

// Основная функция декодирования
std::string base64_decode(const std::string& input) {
    std::string decoded;
    size_t len = input.length();
    size_t i = 0;

    while (i < len) {
        // Считываем 4 символа
        int indices[4];
        int padding_count = 0;

        for (int j = 0; j < 4; ++j) {
            if (i < len) {
                indices[j] = find_base64_index(input[i]);
                if (indices[j] == -1) padding_count++;
                i++;
            }
            else {
                indices[j] = 0;
                padding_count++;
            }
        }

        // Преобразуем 4 индекса в 3 байта
        uint8_t byte1 = (indices[0] << 2) | ((indices[1] & 0x30) >> 4);
        uint8_t byte2 = ((indices[1] & 0x0F) << 4) | ((indices[2] & 0x3C) >> 2);
        uint8_t byte3 = ((indices[2] & 0x03) << 6) | indices[3];

        // Добавляем байты в результат, учитывая padding
        decoded.push_back(byte1);
        if (padding_count < 2) decoded.push_back(byte2);
        if (padding_count < 1) decoded.push_back(byte3);
    }

    return decoded;
}