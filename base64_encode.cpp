#include "base64_encode.h"
#include <string>
#include <vector>
#include <stdexcept>

namespace Base64 {

    // Алфавит Base64 согласно спецификации
    const char ALPHABET[65] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    const char PADDING_CHAR = '=';

    // Кодирование одного байта в символ Base64
    char encodeByte(unsigned char byte) {
        if (byte >= 64) {
            throw std::out_of_range("Byte value out of range for Base64 encoding");
        }
        return ALPHABET[byte];
    }

    // Кодирование триплета байтов (3 байта -> 4 символа Base64)
    std::string encodeTriplet(unsigned char a, unsigned char b, unsigned char c) {
        std::string result(4, ' ');

        // Первый символ: первые 6 бит первого байта
        result[0] = encodeByte((a >> 2) & 0x3F);

        // Второй символ: последние 2 бита первого байта + первые 4 бита второго байта
        result[1] = encodeByte(((a & 0x03) << 4) | ((b >> 4) & 0x0F));

        // Третий символ: последние 4 бита второго байта + первые 2 бита третьего байта
        result[2] = encodeByte(((b & 0x0F) << 2) | ((c >> 6) & 0x03));

        // Четвертый символ: последние 6 бит третьего байта
        result[3] = encodeByte(c & 0x3F);

        return result;
    }

    // Кодирование строки в Base64
    std::string encode(const std::string& input) {
        // Преобразуем строку в вектор байтов для единообразия
        std::vector<unsigned char> data(input.begin(), input.end());
        return encode(data);
    }

    // Кодирование вектора байтов в Base64
    std::string encode(const std::vector<unsigned char>& data) {
        std::string result;
        size_t i = 0;
        size_t len = data.size();

        // Обрабатываем полные триплеты (по 3 байта)
        while (i + 2 < len) {
            result += encodeTriplet(data[i], data[i + 1], data[i + 2]);
            i += 3;
        }

        // Обработка неполного триплета в конце
        if (i < len) {
            // Остался 1 или 2 байта
            if (len - i == 1) {
                // 1 байт: кодируем как 2 символа + 2 padding
                unsigned char a = data[i];
                result += encodeByte((a >> 2) & 0x3F);
                result += encodeByte(((a & 0x03) << 4) & 0x3F);
                result += PADDING_CHAR;
                result += PADDING_CHAR;
            }
            else if (len - i == 2) {
                // 2 байта: кодируем как 3 символа + 1 padding
                unsigned char a = data[i];
                unsigned char b = data[i + 1];
                result += encodeByte((a >> 2) & 0x3F);
                result += encodeByte(((a & 0x03) << 4) | ((b >> 4) & 0x0F));
                result += encodeByte(((b & 0x0F) << 2) & 0x3F);
                result += PADDING_CHAR;
            }
        }

        return result;
    }

} // namespace Base64
