#include <stdio.h>
#include <stdlib.h>

int multiply(int a, int b){
    return a*b;
}

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int main() {
    int choice, a, b;
    int (*functionPointer)(int, int);
    printf("Choose operation: \n"
           "1 - Addition\n"
           "2 - Substraction\n"
           "3 - Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            functionPointer = add;
            break;
        case 2:
            functionPointer = subtract;
            break;
        case 3:
            functionPointer = multiply;
            break;
        default:
            printf("Wrong choice");
            return 1;
    }

    printf("Give two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Result: %d", functionPointer(a, b));

    return 0;
}
