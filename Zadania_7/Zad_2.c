#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        sum += numbersExtraction1(line);
        free(line); // We free memory after each line
    }
    printf("%d", sum);

    fclose(file);
    return 0;
}
