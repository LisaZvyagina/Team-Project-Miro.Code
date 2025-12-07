// Base64Project.cpp (главный файл с тестами)
#include <iostream>
#include <string>
#include "base64_decode.h"
#include "ascii_table.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "=== ЛАБОРАТОРНАЯ РАБОТА №4 ===\n";
    std::cout << "=== Декодирование Base64 ===\n\n";

    // КОНТРОЛЬНЫЕ ЗАДАНИЯ ИЗ ЛАБОРАТОРНОЙ
    std::cout << "=== Контрольные задания (стр. 7) ===\n\n";

    // Задание 4: Раскодировать Pt54
    std::cout << "4. Раскодировать 'Pt54':\n";
    std::string result1 = base64_decode("Pt54");
    std::cout << "   Результат: " << result1 << "\n";
    std::cout << "   ASCII коды: ";
    for (char c : result1) std::cout << (int)c << " ";
    std::cout << "\n";
    std::cout << "   Символы: ";
    for (char c : result1) {
        if (c >= 32 && c <= 126) std::cout << c << " ";
        else std::cout << "? ";
    }
    std::cout << "\n\n";

    // Задание 5: Раскодировать Rj0v
    std::cout << "5. Раскодировать 'Rj0v':\n";
    std::string result2 = base64_decode("Rj0v");
    std::cout << "   Результат: " << result2 << "\n";
    std::cout << "   ASCII коды: ";
    for (char c : result2) std::cout << (int)c << " ";
    std::cout << "\n";
    std::cout << "   Символы: ";
    for (char c : result2) {
        if (c >= 32 && c <= 126) std::cout << c << " ";
        else std::cout << "? ";
    }
    std::cout << "\n\n";

    // Задание 6: Раскодировать zbTM
    std::cout << "6. Раскодировать 'zbTM':\n";
    std::string result3 = base64_decode("zbTM");
    std::cout << "   Результат: " << result3 << "\n";
    std::cout << "   ASCII коды: ";
    for (char c : result3) std::cout << (int)c << " ";
    std::cout << "\n";
    std::cout << "   Символы: ";
    for (char c : result3) {
        if (c >= 32 && c <= 126) std::cout << c << " ";
        else std::cout << "? ";
    }
    std::cout << "\n\n";

   
    return 0;
}