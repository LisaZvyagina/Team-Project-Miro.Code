#include <iostream>
#include <string>
#include "base64_decode.h"
#include "base64_encode.h"
#include "file_io.h"

void showMenu() {
    std::cout << "\n=== Base64 Кодировщик/Декодировщик ===\n";
    std::cout << "1. Закодировать текст из файла\n";
    std::cout << "2. Раскодировать текст из файла\n";
    std::cout << "3. Закодировать текст из консоли\n";
    std::cout << "4. Раскодировать текст из консоли\n";
    std::cout << "5. Выйти\n";
    std::cout << "Выберите действие (1-5): ";
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    std::string input, output, inputFile, outputFile;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::cout << "Введите имя входного файла: ";
            std::getline(std::cin, inputFile);
            std::cout << "Введите имя выходного файла: ";
            std::getline(std::cin, outputFile);
            input = readFile(inputFile);
            if (!input.empty()) {
                output = Base64::encode(input);
                writeFile(outputFile, output);
            }
            break;
        }
        case 2: {
            std::cout << "Введите имя входного файла: ";
            std::getline(std::cin, inputFile);
            std::cout << "Введите имя выходного файла: ";
            std::getline(std::cin, outputFile);
            input = readFile(inputFile);
            if (!input.empty()) {
                output = base64_decode(input);
                writeFile(outputFile, output);
            }
            break;
        }
        case 3: {
            std::cout << "Введите текст для кодирования: ";
            std::getline(std::cin, input);
            output = Base64::encode(input);
            std::cout << "Результат Base64: " << output << std::endl;
            break;
        }
        case 4: {
            std::cout << "Введите текст для декодирования: ";
            std::getline(std::cin, input);
            output = base64_decode(input);
            std::cout << "Результат: " << output << std::endl;
            break;
        }
        case 5: {
            std::cout << "Выход...\n";
            break;
        }
        default: {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 5);

    return 0;
}