#include <stdio.h>

int main() {
    int number = 1;
    int * pNumber = &number;
    *pNumber = 20;
    printf("var value: %d, pointer value %d\n", number, *pNumber);
    return 0;
}
