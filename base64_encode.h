#ifndef BASE64_ENCODE_H
#define BASE64_ENCODE_H

#include <string>
#include <vector>

namespace Base64 {

	std::string encode(const std::string& input);
	std::string encode(const std::vector<unsigned char>& data);

	std::string encodeFile(const std::string& filepath);
	bool encodeFileToFile(const std::string& inputFile, const std::string& outputFile);

	std::string encodeTriplet(unsigned char a, unsigned char b, unsigned char c);
	char encodeByte(unsigned char byte);

	extern const char ALPHABET[65];
	extern const char PADDING_CHAR;

}

#endif

