#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createMatrix(int nRows, int nColumns){
    // Allocate memory for Rows pointers
    int **matrix = (int **)malloc(nRows * sizeof(int*));
    // Initialization of the pseudo-random number generator
    int randomNumber;
    srand(time(NULL));

    for(int i = 0; i < nRows; i++){
        // Allocate memory for Columns
        matrix[i] = (int *)malloc(nColumns * sizeof(int));

        for(int j  = 0; j < nColumns; j++){
            // Drawing a number from 1 to 100
            randomNumber = rand() % 100 + 1;
            matrix[i][j] = randomNumber;
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int nRows, int nColumns){
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nColumns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int nRows){
    for(int i = 0; i < nRows; i++) {
        // Free individual rows
        free(matrix[i]);
    }
    // Free top-level pointer
    free(matrix);
}

int main() {
    int nRows, nColumns;

    printf("Enter number of rows in matrix: \n");
    scanf("%d", &nRows);
    printf("Enter number of columns in matrix: \n");
    scanf("%d", &nColumns);

    int **matrix = createMatrix(nRows, nColumns);
    printMatrix(matrix, nRows, nColumns);
    freeMatrix(matrix, nRows);
    return 0;
}
