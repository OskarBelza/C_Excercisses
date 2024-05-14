#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int borderValue[] = {12, 13, 14};
const char polishShorts[] = {'c', 'z', 'n'};
const char englishShorts[] = {'r', 'g', 'b'};

char* getLine(FILE *file) {
    char *line = NULL; // Pointer to buffer with line from file
    int ch; // Auxiliary variable with char from line
    size_t size = 0; // Size of buffer
    size_t len = 0; // Len of line in time

    // We iterate through line until we meet new line or end of file
    while ((ch = fgetc(file)) != EOF && ch != '\n') {

        // We check if buffer has good size if not we double it and reallocate memory
        if (len + 1 >= size) {
            size = size == 0 ? 128 : size * 2;
            line = realloc(line, size);
            // Condition to check if reallocation was successful
            if (line == NULL) {
                perror("Błąd alokacji pamięci");
                exit(EXIT_FAILURE);
            }
        }
        // After we increase size of buffer we assign new char to the end of line
        line[len++] = (char)ch;
    }

    // If End of File we return null
    if (len == 0 && ch == EOF) {
        free(line);
        return NULL;
    }
    else{
        line[len++] = '\0'; // We add null character to the end of line to create string in C
        return line;
    }
}

int gameNumber(const char *line){
    int number = 0;
    // We iterate through start of the line until we meet :
    // Which is where game number ends
    for(int i = 0; line[i] != ':'; i++){
        // We extract our game number
        if(isdigit(line[i]) && number == 0){
            number = line[i] - '0';
        }
        else if(isdigit(line[i]) && number != 0) {
            number *= 10;
            number += line[i] - '0';
        }
    }
    return number;
}

int checkDices(const char *line){
    int i = 0;
    int tempNumber = 0;
    // We skip game to start reading colors values
    // Game always end after : so we choose this in our while condition
    while(line[i] != ':'){
        i++;
    }
    while(line[i] != '\0'){
        // We check if read value is digit and if our temp number is empty
        // If yes we assign this digit tou our temp variable
        if(isdigit(line[i]) && tempNumber == 0){
            tempNumber = line[i] - '0';
        }
            // If it is a digit but temp is not empty we have to multiply our temp and add new digit
            // We're doing this to correctly read double and more digits
        else if(isdigit(line[i]) && tempNumber != 0){
            tempNumber *= 10;
            tempNumber += line[i] - '0';
        }
            // We check if color after our digit is red
        else if(line[i] == englishShorts[0]){
            // If yes we check our borderValue condition
            if(tempNumber > borderValue[0]){
                // If it is greater we return 0 because it means that we exceeded our value
                return 0;
            }
            // We skip rest of the letters from word red and 0'ed temp number
            // So we can read the next value correctly
            i +=2;
            tempNumber = 0;
        }
            // The same as previous but for color green
        else if(line[i] == englishShorts[1]){
            if(tempNumber > borderValue[1]){
                return 0;
            }
            i += 4;
            tempNumber = 0;
        }
            // The same as previous but for color blue
        else if(line[i] == englishShorts[2]){
            if(tempNumber > borderValue[2]){
                return 0;
            }
            i += 3;
            tempNumber = 0;
        }
        // We iterate through char table, so we have to increase our index on the end
        i++;
    }
    // If we didn't return 0 through our while we check tha game number extract this value
    // and return as our result
    return gameNumber(line);
}

int main() {
    FILE *file = fopen("..\\Zadania_7\\Data_2.txt", "r");
    if (file == NULL) {
        perror("File opening error");
        return EXIT_FAILURE;
    }

    // We read our file line after line with our function getLine
    char *line;
    // Sum of games number that check condition
    int gamesSum = 0;
    while ((line = getLine(file)) != NULL) {
        gamesSum += checkDices(line);
    }
    printf("%d", gamesSum);

    fclose(file);
    return 0;
}
