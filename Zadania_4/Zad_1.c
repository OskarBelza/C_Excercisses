#include <stdlib.h>
#include <stdio.h>

unsigned int factorial(unsigned int x){
    if(x < 2){
        return 1;
    }
    else{
        return x * factorial(x-1);
    }
}

int main(){
    printf("%d", factorial(0));
    return 0;
}