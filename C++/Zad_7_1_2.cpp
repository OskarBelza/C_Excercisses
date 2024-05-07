#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int numbersExtraction(const string &line) {
    int firstNumber = 0;
    int lastNumber = 0;

    // We iterate through our line from beginning until we find first number
    for (char ch : line) {
        if (isdigit(ch)) {
            firstNumber = ch - '0';
            break;
        }
    }
    // We iterate through our line from the end until we find last number
    for (string::size_type i = line.size() - 1; i >= 0; i--) {
        char ch = line[i];
        if (isdigit(ch)) {
            lastNumber = ch - '0';
            break;
        }
    }

    // If we didn't find any number we return 0 else we return first time 10 plus last
    return (firstNumber * 10) + lastNumber;
}

int main() {
    ifstream file("..\\C++\\Data_1.txt");
    if (!file.is_open()) {
        cerr << "File opening error" << endl;
        return EXIT_FAILURE;
    }

    // We read our file line after line with std::getline
    string line;
    int sum = 0;
    while (getline(file, line)) {
        sum += numbersExtraction(line);
    }
    cout << sum;

    file.close();
    return 0;
}
