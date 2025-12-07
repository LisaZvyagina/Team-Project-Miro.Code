#ifndef BASE64_ENCODE_H
#define BASE64_ENCODE_H

#include <string>
#include <vector>

namespace Base64 {

	// Базовые функции кодирования
	std::string encode(const std::string& input);
	std::string encode(const std::vector<unsigned char>& data);

	// Функции для работы с файлами
	std::string encodeFile(const std::string& filepath);
	bool encodeFileToFile(const std::string& inputFile, const std::string& outputFile);

	// Вспомогательные функции
	std::string encodeTriplet(unsigned char a, unsigned char b, unsigned char c);
	char encodeByte(unsigned char byte);

	// Константы
	extern const char ALPHABET[65];
	extern const char PADDING_CHAR;

} // namespace Base64

#endif // BASE64_ENCODE_H
