#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

unordered_map<string, int> numberWords = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

int getNumber(const string &word) {
    auto it = numberWords.find(word);
    return (it != numberWords.end()) ? it->second : -1;
}

int numbersExtraction(const string &line) {
    int firstNumber = -1;
    int lastNumber = -1;

    // Finding the first number
    for(size_t i = 0; i < line.size(); i++) {
        if(isdigit(line[i])) {
            firstNumber = line[i] - '0';
            break;
        } else {
            string word;
            for(int j = i; j < line.size(); j++) {
                word += tolower(line[j]);
                int num = getNumber(word);
                if(num != -1) {
                    firstNumber = num;
                    break;
                }
            }
            if(firstNumber != -1) {
                break;
            }
        }
    }

    // Finding the last number
    for(int i = line.size() - 1; i >= 0; i--) {
        if(isdigit(line[i])) {
            lastNumber = line[i] - '0';
            break;
        } else {
            string word;
            for(int j = i; j >= 0; j--) {
                word = tolower(line[j]) + word;
                int num = getNumber(word);
                if(num != -1) {
                    lastNumber = num;
                    break;
                }
            }
            if(lastNumber != -1) {
                break;
            }
        }
    }

    // If we didn't find any number we return 0
    if(firstNumber == -1 && lastNumber == -1) {
        return 0;
    }

    // If we had only one digit in line we have to assign first number to the last number also
    if(lastNumber == -1) {
        lastNumber = firstNumber;
    }

    // Return the sum of the first and last numbers
    return (firstNumber * 10) + lastNumber;
}

int main() {
    ifstream file("..\\Zadania_7\\Data_1_test.txt");
    if (!file.is_open()) {
        cerr << "File opening error" << endl;
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
