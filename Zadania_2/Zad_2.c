#include <stdio.h>

void doubleFloat (float *number){
    *number *= 2;
}

int main() {
    float num = 1.5;
    doubleFloat(&num);
    printf("Value of num %.2f", num);
    return 0;
}

