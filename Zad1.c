#include <stdio.h>
#include <stdlib.h>

int main1() {
    char name[15];

    printf("Enter your name\n");
    scanf("%s", name);
    printf("Hello, %s", name);

    return 0;
}
