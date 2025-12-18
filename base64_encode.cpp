#include "base64_encode.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

namespace Base64 {

    const char ALPHABET[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const char PADDING_CHAR = '=';

    char encodeByte(unsigned char byte) {
        return ALPHABET[byte];
    }

    std::string encodeTriplet(unsigned char a, unsigned char b, unsigned char c) {
        std::string result(4, ' ');
        result[0] = encodeByte((a >> 2) & 0x3F);
        result[1] = encodeByte(((a & 0x03) << 4) | ((b >> 4) & 0x0F));
        result[2] = encodeByte(((b & 0x0F) << 2) | ((c >> 6) & 0x03));
        result[3] = encodeByte(c & 0x3F);
        return result;
    }

    std::string encode(const std::string& input) {
        std::vector<unsigned char> data(input.begin(), input.end());
        return encode(data);
    }

    std::string encode(const std::vector<unsigned char>& data) {
        std::string result;
        size_t i = 0;
        size_t len = data.size();

        while (i + 2 < len) {
            result += encodeTriplet(data[i], data[i + 1], data[i + 2]);
            i += 3;
        }

        if (i < len) {
            if (len - i == 1) {
                unsigned char a = data[i];
                result += encodeByte((a >> 2) & 0x3F);
                result += encodeByte(((a & 0x03) << 4));
                result += PADDING_CHAR;
                result += PADDING_CHAR;
            }
            else if (len - i == 2) {
                unsigned char a = data[i];
                unsigned char b = data[i + 1];
                result += encodeByte((a >> 2) & 0x3F);
                result += encodeByte(((a & 0x03) << 4) | ((b >> 4) & 0x0F));
                result += encodeByte(((b & 0x0F) << 2));
                result += PADDING_CHAR;
            }
        }

        return result;
    }

    std::string encodeFile(const std::string& filepath) {
        std::ifstream file(filepath, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Cannot open file: " + filepath);
        }
        
        std::string content((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
        return encode(content);
    }

    bool encodeFileToFile(const std::string& inputFile, const std::string& outputFile) {
        try {
            std::string encoded = encodeFile(inputFile);
            std::ofstream out(outputFile, std::ios::binary);
            if (!out) return false;
            out << encoded;
            return true;
        } catch (...) {
            return false;
        }
    }

}

