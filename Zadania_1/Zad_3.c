#include <stdio.h>
#include <stdlib.h>

long factorial(int number){
    if (number == 0){
        return 1;
    }
    else {
        return (number * factorial(number - 1));
    }
}

void arrayFactorial(int array[], int size){
    int resultArray[size];
    for(int i = 0; i < size; i++){
        int fact = factorial(array[i]);
        resultArray[i] = fact;

        printf("Factorial of %d is: %d\n", i+1, resultArray[i]);
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arrayLen = sizeof(array) / sizeof(array[0]);
    arrayFactorial(array, arrayLen);

    return 0;
}
