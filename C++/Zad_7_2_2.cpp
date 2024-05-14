#include <iostream>
#include <fstream>
#include <string>

const char englishShorts[] = {'r', 'g', 'b'};

int checkDices(const std::string &line) {
    int i = 0;
    int tempNumber = 0;
    // We set our maxes values as 0 in the beginning
    int maxRed = 0;
    int maxGreen = 0;
    int maxBlue = 0;
    // We skip the game number part
    while (line[i] != ':') {
        i++;
    }
    while (line[i] != '\0') {
        // We extract number before color
        if (isdigit(line[i]) && tempNumber == 0) {
            tempNumber = line[i] - '0';
        }
            // Condition to properly extract double and more digits
        else if (isdigit(line[i]) && tempNumber != 0) {
            tempNumber *= 10;
            tempNumber += line[i] - '0';
        }
            // We check if the color after our digit is red
        else if (line[i] == englishShorts[0]) {
            // If yes we check if it's greater than our max
            if (tempNumber > maxRed) {
                // If yes we change our max to this new digit
                maxRed = tempNumber;
            }
            // We skip the rest of the letters from the word "red" and 0 our temp value
            i += 2;
            tempNumber = 0;
        }
            // Same as previous but for color green
        else if (line[i] == englishShorts[1]) {
            if (tempNumber > maxGreen) {
                maxGreen = tempNumber;
            }
            i += 4;
            tempNumber = 0;
        }
            // Same as previous but for color blue
        else if (line[i] == englishShorts[2]) {
            if (tempNumber > maxBlue) {
                maxBlue = tempNumber;
            }
            i += 3;
            tempNumber = 0;
        }
        // We iterate through the char table, so we have to increase our index in the end
        i++;
    }
    // We return the result of the multiplication of our 3 maxes
    return maxBlue * maxRed * maxGreen;
}

int main() {
    std::ifstream file("..\\Zadania_7\\Data_2.txt");
    if (!file.is_open()) {
        std::cerr << "File opening error" << std::endl;
        return EXIT_FAILURE;
    }

    // Sum of multiplication of maxes
    int gamesSum = 0;
    std::string line;
    while (std::getline(file, line)) {
        gamesSum += checkDices(line);
    }
    std::cout << gamesSum << std::endl;

    file.close();
    return 0;
}
