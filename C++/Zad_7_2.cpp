#include <iostream>
#include <fstream>
#include <string>

const int borderValue[] = {12, 13, 14};
const char polishShorts[] = {'c', 'z', 'n'};
const char englishShorts[] = {'r', 'g', 'b'};

int gameNumber(const std::string &line){
    int number = 0;
    size_t pos = line.find(':');
    if (pos != std::string::npos) {
        for (size_t i = 0; i < pos; i++) {
            if (isdigit(line[i]) && number == 0) {
                number = line[i] - '0';
            }
            else if (isdigit(line[i]) && number != 0) {
                number *= 10;
                number += line[i] - '0';
            }
        }
    }
    return number;
}

int checkDices(const std::string &line){
    int tempNumber = 0;
    size_t pos = line.find(':');
    if (pos != std::string::npos) {
        for (size_t i = pos + 1; i < line.size(); i++) {
            if (isdigit(line[i]) && tempNumber == 0) {
                tempNumber = line[i] - '0';
            }
            else if (isdigit(line[i]) && tempNumber != 0) {
                tempNumber *= 10;
                tempNumber += line[i] - '0';
            }
            else if (line[i] == englishShorts[0]) {
                if (tempNumber > borderValue[0]) {
                    return 0;
                }
                i += 2;
                tempNumber = 0;
            }
            else if (line[i] == englishShorts[1]) {
                if (tempNumber > borderValue[1]) {
                    return 0;
                }
                i += 4;
                tempNumber = 0;
            }
            else if (line[i] == englishShorts[2]) {
                if (tempNumber > borderValue[2]) {
                    return 0;
                }
                i += 3;
                tempNumber = 0;
            }
        }
    }
    return gameNumber(line);
}

int main() {
    std::ifstream file("..\\Zadania_7\\Data_2.txt");
    if (!file.is_open()) {
        std::cerr << "File opening error" << std::endl;
        return EXIT_FAILURE;
    }

    int gamesSum = 0;
    std::string line;
    while (std::getline(file, line)) {
        gamesSum += checkDices(line);
    }
    std::cout << gamesSum << std::endl;

    file.close();
    return 0;
}
