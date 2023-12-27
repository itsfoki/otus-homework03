#include <iostream>

#include "game.h"
#include "inputCheck.h"

// target_value - загаданное число, maxNumber - максимальное число
int game(const unsigned int target_value, const unsigned int maxNumber = 100) {  
    int tryCount = 0;
    int current_value = 0;

    std::cout << "Number interval from 0 to " << maxNumber << ":\n";
    std::cout << "Enter your guess:\n";
    std::string str;

    do {
        current_value = inputCheck::getUserNumber();

        tryCount++;

        if (current_value > target_value) {
            std::cout << "less than " << current_value << "\n";
        } else if (current_value < target_value) {
            std::cout << "greater than " << current_value << "\n";
        } else {
            std::cout << "You WIN !!!\n";
            break;
        }
    } while (true);

    return tryCount;
}