#include <iostream>
#include <string>
#include "base64_encode.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "=== Кодирование Base64 ===\n\n";

    std::cout << "=== Контрольные задания ===\n\n";

    // Задание 1: Закодировать Xz25
    std::cout << "1. Закодировать 'Xz25':\n";
    std::string result1 = Base64::encode("Xz25");
    std::cout << "   Результат: " << result1 << "\n";
    std::cout << "   Длина: " << result1.length() << " символов\n";
    std::cout << "   Проверка padding: ";
    if (result1.length() % 4 == 0) {
        std::cout << "Корректно (длина кратна 4)\n";
    }
    else {
        std::cout << "Ошибка (длина не кратна 4)\n";
    }
    std::cout << "\n";

    // Задание 2: Закодировать Fh7k
    std::cout << "2. Закодировать 'Fh7k':\n";
    std::string result2 = Base64::encode("Fh7k");
    std::cout << "   Результат: " << result2 << "\n";
    std::cout << "   Длина: " << result2.length() << " символов\n";
    std::cout << "   Проверка padding: ";
    if (result2.length() % 4 == 0) {
        std::cout << "✓ Корректно (длина кратна 4)\n";
    }
    else {
        std::cout << "✗ Ошибка (длина не кратна 4)\n";
    }
    std::cout << "\n";

    // Задание 3: Закодировать gRn4
    std::cout << "3. Закодировать 'gRn4':\n";
    std::string result3 = Base64::encode("gRn4");
    std::cout << "   Результат: " << result3 << "\n";
    std::cout << "   Длина: " << result3.length() << " символов\n";
    std::cout << "   Проверка padding: ";
    if (result3.length() % 4 == 0) {
        std::cout << "✓ Корректно (длина кратна 4)\n";
    }
    else {
        std::cout << "✗ Ошибка (длина не кратна 4)\n";
    }
    std::cout << "\n";

    std::cout << "=== РЕЗУЛЬТАТЫ ДЛЯ ОТЧЕТА ===\n";
    std::cout << "1. Xz25 -> " << result1 << "\n";
    std::cout << "2. Fh7k -> " << result2 << "\n";
    std::cout << "3. gRn4 -> " << result3 << "\n";

    std::cout << "\nНажмите Enter для выхода...";
    std::cin.get();

    return 0;
}