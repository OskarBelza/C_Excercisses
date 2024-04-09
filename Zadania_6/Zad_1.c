#include <stdio.h>
#include <stdlib.h>

union Data{
    int intType;
    float floatType;
    char charType;
};

int main() {
    union Data data;

    data.intType = 20;
    printf("Value stored in union(int): %d\n", data.intType);

    data.floatType = 5.68;
    printf("Value stored in union(float): %.2f\n", data.floatType);

    data.charType = 'A';
    printf("Value stored in union(char): %c\n", data.charType);

    return 0;
}
