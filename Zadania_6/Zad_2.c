#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10];
    int *pointer;

    for(int i = 0; i < 10; i++){
        array[i] = i;
    }

    pointer = array;
    for(int i = 0; i < 10; i++){
        printf("address: %x - has value %d\n", pointer, *pointer);
        pointer++;
    }
    return 0;
}
