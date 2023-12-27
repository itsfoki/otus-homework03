
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>

#include "fileTable.h"
#include "print.h"

namespace highScore {

   // Запись игроков
    void write(const std::string &userName, int tryCount) {
        std::fstream file("../high_scores.txt", std::fstream::out | std::fstream::app);
        if (!file.is_open()) {
            std::cout << "ERROR Can't open file";
        }
        file << userName << " " << tryCount << "\n";
    }


    // Таблица рекордов
    void print() {
        std::fstream file("../high_scores.txt", std::fstream::in);
        if (!file.is_open()) {
            std::cout << "ERROR Can't open file";
        }

        std::map<std::string, int> tableReaded;
        std::string name;
        int score;

        while (!file.eof()) {
            file >> name >> score;
            // Если имя уже есть в таблице и значение , то проверяем новое значение со старым
            auto search = tableReaded.find(name);
            if (search == tableReaded.end()) {
                tableReaded.insert(std::make_pair(name, score));
            } else if (search != tableReaded.end() && search->second > score) {
                search->second = score;
            }
        }

        std::map<int, std::string> tableToOutput;
        for (auto &row: tableReaded) {
            tableToOutput.insert(std::make_pair(row.second, row.first));
        }

        print::highScore(tableToOutput);
    }
}
