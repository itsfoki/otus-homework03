
#ifndef FINDNUMBER_PRINT_H
#define FINDNUMBER_PRINT_H

#include <map>
#include <string>

namespace print {

    void clearScreen();
    void highScore(std::map<int, std::string>& tableToOutput);
    void menu();
};

#endif