#include <iostream>
#include <algorithm>

#include "game.h"
#include "inputCheck.h"
#include "getRandomNumber.h"
#include "fileTable.h"
#include "print.h"

unsigned int maxNumber = 100;

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);

    std::vector<std::string> arguments;
    if (argc >= 2) {
        for (auto i = 1; i < argc; ++i) {
            arguments.push_back(argv[i]);
        }

        auto tablePos = std::find(arguments.begin(), arguments.end(), "-table");
        if (tablePos != arguments.end()) {
            highScore::print();
            exit(0);
        }

        auto maxPos = std::find(arguments.begin(), arguments.end(), "-max");
        if (maxPos != arguments.end()) {
            if (std::find(arguments.begin(), arguments.end(), "-level") != arguments.end()) {
                std::cout << "Wrong combination of arguments\n";
                exit(0);
            } else if ((maxPos + 1) != arguments.end() && inputCheck::is_integer(*(maxPos + 1))) {
                maxNumber = std::stoi(*(maxPos + 1));
                if (maxNumber < 10) maxNumber = 10;
                if (maxNumber > 100) maxNumber = 100;
            } else {
                std::cout << "After -max needed integer number from 10 to 100\n";
                exit(0);
            }
        }

        auto levelPos = std::find(arguments.begin(), arguments.end(), "-level");
        if (levelPos != arguments.end()) {
            if (std::find(arguments.begin(), arguments.end(), "-max") != arguments.end()) {
                std::cout << "Wrong combination of arguments\n";
                exit(0);
            } else if ((levelPos + 1) != arguments.end() && inputCheck::is_integer(*(levelPos + 1))) {
                int level = std::stoi(*(levelPos + 1));
                if (level <= 1) maxNumber = 10;
                if (level == 2) maxNumber = 50;
                if (level >= 3) maxNumber = 100;
            } else {
                std::cout << "After -level needed 1, 2 or 3\n";
                exit(0);
            }
        }
    }

    do {
        print::menu();

        switch (inputCheck::getMenuNumber()) {
            case 1: {
                system("cls");
                do {
                    // Компьютер загадывает число
                    unsigned int targetNumber = getRandomNumber(maxNumber);

                    // Человек отгадывает
                    int tryCount = game(targetNumber, maxNumber);
                    std::cout << "The number of Your attempts: " << tryCount << "\n";

                    // Вводим имя пользователя
                    std::cout << "Hi, Enter your name - ";
                    std::string userName = inputCheck::getUserName();

                    // Сохраняем в таблицу рекордов
                    highScore::write(userName, tryCount);

                    // Играть ещё или выход в меню
                    std::cout << "\nPlay again? y/n" << "\n";
                } while (inputCheck::getYN());
                break;
            }
            case 2: {
                // 2. Таблица рекордов
                highScore::print();
                std::cout << "\nReturn? y/n" << "\n";
                if (!inputCheck::getYN()) exit(0);
                break;
            }
            case 3:
                // 3. Выход
                return 0;
        }
    } while (true);
}
