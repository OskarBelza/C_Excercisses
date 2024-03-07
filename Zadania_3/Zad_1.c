#include <stdio.h>
#include <stdlib.h>

int** createTriangle(int n){
    // Allocate memory for Rows pointers
    int **triangle = (int **)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        // Allocate memory for Columns
        triangle[i] = (int *)malloc((i+1) * sizeof(int));
        // Assigning 1 value fo first and last column
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j  = 1; j < i; j++){
            // Assigning value from 2 cells above to middle columns
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    return triangle;
}

void printTriangle(int **triangle, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

void freeTriangle(int **triangle, int n){
    for(int i = 0; i < n; i++){
        // Free individual rows
        free(triangle[i]);
    }
    // Free top-level pointer
    free(triangle);
}

int main() {
    int n;
    printf("Enter height of triangle: \n");
    scanf("%d", &n);

    int **triangle = createTriangle(n);
    printTriangle(triangle, n);
    freeTriangle(triangle, n);
    return 0;
}
