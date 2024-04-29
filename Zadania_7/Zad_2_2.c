#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int checkDices(const char *line){
    int i = 0;
    int tempNumber = 0;
    // We set our maxes vales as 0 in the beginning
    int maxRed = 0;
    int maxGreen = 0;
    int maxBlue = 0;
    // We skip game number part
    while(line[i] != ':'){
        i++;
    }
    while(line[i] != '\0'){
        // We extract number before color
        if(isdigit(line[i]) && tempNumber == 0){
            tempNumber = line[i] - '0';
        }
        // Condition to properly extract double and more digits
        else if(isdigit(line[i]) && tempNumber != 0){
            tempNumber *= 10;
            tempNumber += line[i] - '0';
        }
        // We check if color after our digit is red
        else if(line[i] == englishShorts[0]){
            // If yes we check is it greater than our max
            if(tempNumber > maxGreen){
                // If yes we change our max to this new digit
                maxGreen = tempNumber;
            }
            // We skip rest of the letters from word red an 0 our temp value
            i +=2;
            tempNumber = 0;
        }
        // Same as previous but for color green
        else if(line[i] == englishShorts[1]){
            if(tempNumber > maxRed){
                maxRed = tempNumber;
            }
            i += 4;
            tempNumber = 0;
        }
        // Same as previous but for color blue
        else if(line[i] == englishShorts[2]){
            if(tempNumber > maxBlue){
                maxBlue = tempNumber;
            }
            i += 3;
            tempNumber = 0;
        }
        // We iterate through char table, so we have to increase our index on the end
        i++;
    }
    // We return result of multiplication of our 3 maxes
    return maxBlue*maxRed*maxGreen;
}

int main() {
    FILE *file = fopen("C:\\Users\\48512\\CLionProjects\\C_Excercisses\\Zadania_7\\Data_2_test.txt", "r");
    if (file == NULL) {
        perror("File opening error");
        return EXIT_FAILURE;
    }

    // We read our file line after line with our function getLine
    char *line;
    // Sum of multiplication of maxes
    int gamesSum = 0;
    while ((line = getLine(file)) != NULL) {
        gamesSum += checkDices(line);
    }
    printf("%d", gamesSum);

    fclose(file);
    return 0;
}
