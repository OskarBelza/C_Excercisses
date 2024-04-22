#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funkcja pomocnicza do konwersji słownych reprezentacji liczb na ich numeryczne odpowiedniki
int wordToNumber(const char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // Nieznane słowo
}

// Funkcja pomocnicza do konwersji liczby zapisanej jako ciąg znaków na liczbę całkowitą
int parseNumber(const char *str) {
    int result = 0;
    int length = strlen(str);

    for (int i = 0; i < length; ++i) {
        if (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } else if (isalpha(str[i])) {
            // Jeśli napotkamy słowną reprezentację liczby, użyj funkcji wordToNumber() do konwersji
            char word[20]; // Zakładamy, że słowo nie będzie dłuższe niż 20 znaków
            int j = 0;
            while (isalpha(str[i])) {
                word[j++] = str[i++];
            }
            word[j] = '\0';
            int num = wordToNumber(word);
            if (num != -1) {
                result = result * 10 + num;
            } else {
                // Ignorujemy nieznane słowo
                --i; // cofamy iterator, aby nie pominąć następnego znaku po słowie
            }
        }
    }

    return result;
}

int main() {
    const char *line = "abcone2threexyz";
    int number = parseNumber(line);
    printf("Odczytana liczba: %d\n", number);
    return 0;
}
