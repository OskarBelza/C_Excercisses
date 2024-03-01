#include <stdio.h>
#include <stdlib.h>

int threeAndFiveMultiple(int number){
    int result = 0;
    if (number < 0){
        return 0;
    }
    for(int i = 0; i < number; i++){
        if (i % 3 == 0 || i % 5 == 0){
            result += i;
        }
    }
    return result;
}

int main() {
    int number;

    printf("Enter a number\n");
    scanf("%d", &number);
    printf("Sum of numbers that are multiple of 3 and 5 below %d is %d", number, threeAndFiveMultiple(number));

    return 0;
}
