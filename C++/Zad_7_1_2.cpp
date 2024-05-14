#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int wordToNumber(const string &word) {
    if (word == "zero") return 0;
    if (word == "one") return 1;
    if (word == "two") return 2;
    if (word == "three") return 3;
    if (word == "four") return 4;
    if (word == "five") return 5;
    if (word == "six") return 6;
    if (word == "seven") return 7;
    if (word == "eight") return 8;
    if (word == "nine") return 9;
    return -1;
}

int numbersExtraction(const string &line) {
    int firstNumber = -1;
    int lastNumber = -1;
    int temp;

    for (int i = 0; i < line.size(); i++) {
        if (isdigit(line[i])) {
            temp = line[i] - '0';
            firstNumber = temp;
            break;
        } else {
            switch (line[i]) {
                case 'o':
                    temp = wordToNumber(line.substr(i, 3));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                case 't':
                    temp = wordToNumber(line.substr(i, 3));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    temp = wordToNumber(line.substr(i, 5));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    break;
                case 'f':
                    temp = wordToNumber(line.substr(i, 4));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    temp = wordToNumber(line.substr(i, 4));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    break;
                case 's':
                    temp = wordToNumber(line.substr(i, 3));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    temp = wordToNumber(line.substr(i, 5));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    break;
                case 'e':
                    temp = wordToNumber(line.substr(i, 5));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    break;
                case 'n':
                    temp = wordToNumber(line.substr(i, 4));
                    if (temp != -1) {
                        firstNumber = temp;
                        break;
                    }
                    break;
            }
        }
        if (firstNumber != -1) {
            break;
        }
    }

    // Szukanie ostatniej liczby od końca
    for (int i = line.size() - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            temp = line[i] - '0';
            lastNumber = temp;
            break;
        } else {
            switch (line[i]) {
                case 'o':
                    temp = wordToNumber(line.substr(i, 3));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    break;
                case 't':
                    temp = wordToNumber(line.substr(i, 3));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    temp = wordToNumber(line.substr(i, 5));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    break;
                case 'f':
                    temp = wordToNumber(line.substr(i, 4));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    temp = wordToNumber(line.substr(i, 4));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    break;
                case 's':
                    temp = wordToNumber(line.substr(i, 3));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    temp = wordToNumber(line.substr(i, 5));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    break;
                case 'e':
                    temp = wordToNumber(line.substr(i, 5));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    break;
                case 'n':
                    temp = wordToNumber(line.substr(i, 4));
                    if (temp != -1) {
                        lastNumber = temp;
                        break;
                    }
                    break;
            }
        }
        if (lastNumber != -1) {
            break;
        }
    }

    return (firstNumber + lastNumber == -2) ? 0 : (firstNumber * 10) + lastNumber;
}

int main() {
    ifstream file("..\\Zadania_7\\Data_1.txt");
    if (!file.is_open()) {
        cerr << "File opening error\n";
        return EXIT_FAILURE;
    }

    string line;
    int sum = 0;
    while (getline(file, line)) {
        sum += numbersExtraction(line);
    }
    cout << sum;

    file.close();
    return 0;
}
