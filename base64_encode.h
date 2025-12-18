#ifndef BASE64_ENCODE_H
#define BASE64_ENCODE_H

#include <string>
#include <vector>

namespace Base64 {
    std::string encode(const std::string& input);
    std::string encode(const std::vector<unsigned char>& data);
}

#endif


