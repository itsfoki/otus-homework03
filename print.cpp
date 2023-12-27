
#include <iostream>
#include <iomanip>
#include "print.h"

namespace print {

    // Таблица рекордов
    void highScore(std::map<int, std::string>& tableToOutput) {
        system("cls");
        std::cout << "High scores table:"<< "\n";
        for (auto &row: tableToOutput) {
            std::cout << std::left << row.second << " - "
                      << std::right << row.first << "\n";
        }
    }

    // Меню игры
    void menu() {
        system("cls");
        std::cout << "Welcome to the guess the number game" << "\n";
        std::cout << "\n";
        std::cout << "1. New game" << "\n";
        std::cout << "2. High scores" << "\n";
        std::cout << "3. Exit" << "\n";
    }
}