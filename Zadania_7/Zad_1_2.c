#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

void firstOrLast(int *firstNumber, int *lastNumber, int number){
    // First we check if it's -1
    if(number == -1){
        // if yes we exit function and don't change our numbers
        return;
    }
    // Then we check if we assign our number to first number or later
    if(*firstNumber == -1){
        *firstNumber = number;
    } else{
        *lastNumber = number;
    }
}

int checkOne(const char *line, int start){
    // We create variable to contain our potential number
    char potentialOne[4];
    // This function extract 3 letters from moment we find o in our line
    // So if it's our number we extract "one"
    memcpy(potentialOne, &line[start], 3);
    // We add end of line to create string
    potentialOne[3] = '\0';
    // We check if our potential number is really one
    if (strcmp(potentialOne, "one") == 0){
        return 1;
    }
    else{
        // if not we return -1 to mark that
        return -1;
    }
    // Rest of the functions work the same but for each individual number
}

int checkTwo(const char *line, int start){
    char potentialTwo[4];
    memcpy(potentialTwo, &line[start], 3);
    potentialTwo[3] = '\0';
    if (strcmp(potentialTwo, "two") == 0){
        return 2;
    }
    else{
        return -1;
    }
}

int checkThree(const char *line, int start){
    char potentialThree[6];
    memcpy(potentialThree, &line[start], 5);
    potentialThree[5] = '\0';
    if (strcmp(potentialThree, "three") == 0){
        return 3;
    }
    else{
        return -1;
    }
}

int checkFour(const char *line, int start){
    char potentialFour[5];
    memcpy(potentialFour, &line[start], 4);
    potentialFour[4] = '\0';
    if (strcmp(potentialFour, "four") == 0){
        return 4;
    }
    else{
        return -1;
    }
}

int checkFive(const char *line, int start){
    char potentialFive[5];
    memcpy(potentialFive, &line[start], 4);
    potentialFive[4] = '\0';
    if (strcmp(potentialFive, "five") == 0){
        return 5;
    }
    else{
        return -1;
    }
}

int checkSix(const char *line, int start){
    char potentialSix[4];
    memcpy(potentialSix, &line[start], 3);
    potentialSix[3] = '\0';
    if (strcmp(potentialSix, "six") == 0){
        return 6;
    }
    else{
        return -1;
    }
}

int checkSeven(const char *line, int start){
    char potentialSeven[6];
    memcpy(potentialSeven, &line[start], 5);
    potentialSeven[5] = '\0';
    if (strcmp(potentialSeven, "seven") == 0){
        return 7;
    }
    else{
        return -1;
    }
}

int checkEight(const char *line, int start){
    char potentialEight[6];
    memcpy(potentialEight, &line[start], 5);
    potentialEight[5] = '\0';
    if (strcmp(potentialEight, "eight") == 0){
        return 8;
    }
    else{
        return -1;
    }
}

int checkNine(const char *line, int start){
    char potentialNine[5];
    memcpy(potentialNine, &line[start], 4);
    potentialNine[4] = '\0';
    if (strcmp(potentialNine, "nine") == 0){
        return 9;
    }
    else{
        return -1;
    }
}

int numbersExtraction(const char *line){
    int firstNumber = -1;
    int lastNumber = -1;
    int temp;
    for(int i = 0; line[i] != '\0'; i++){
        // if it is digit we just check is it first number or not
        if(isdigit(line[i])){
            temp = line[i] - '0';
            firstOrLast(&firstNumber, &lastNumber, temp);
        }
        // if it's not digit we check is it letter that any number begin with
        switch (line[i]) {
            case 'o':
                // We have function to every number if number fit i returns
                // the number if not it returns -1
                temp = checkOne(line, i);
                // then we check is it -1 and if not is it our first or later number
                firstOrLast(&firstNumber, &lastNumber, temp);
            case 't':
                temp = checkTwo(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
                temp = checkThree(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
            case 'f':
                temp = checkFour(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
                temp = checkFive(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
            case 's':
                temp = checkSix(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
                temp = checkSeven(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
            case 'e':
                temp = checkEight(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
            case 'n':
                temp = checkNine(line, i);
                firstOrLast(&firstNumber, &lastNumber, temp);
        }
    }
    // if last number is still -1 then our last number is also our first number
    if(lastNumber == -1){
        lastNumber = firstNumber;
    }
    // If we didn't find any number we return 0 else we return first time 10 plus last
    return firstNumber+lastNumber == -2 ? 0 : (firstNumber*10)+lastNumber;
}

int main() {
    FILE *file = fopen("C:\\Users\\48512\\CLionProjects\\C_Excercisses\\Zadania_7\\Data_1.txt", "r");
    if (file == NULL) {
        perror("File opening error");
        return EXIT_FAILURE;
    }

    // We read our file line after line with our function getLine
    char *line;
    int sum = 0;
    while ((line = getLine(file)) != NULL) {
        sum += numbersExtraction(line);
        free(line); // We free memory after each line
    }
    printf("%d", sum);

    fclose(file);
    return 0;
}
