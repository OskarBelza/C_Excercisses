#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isDuplicate(const int *array, int i, int start){
    for(int j = start; j < i; j++){
        if (array[j] == array[i]){
            return 1;
        }
    }
    return 0;
}

void permute(int *array, int start, int end){
    // When we go through whole array we print our permutation
    if (start == end){
        for(int i = 0; i <= end; i++){
            printf("%d, ", array[i]);
        }
        printf("\n");
    }
    else{
        // We go through array and swap values
        for(int i = start; i <= end; i++){
            // Flag to check duplicates
            int duplicateFlag = isDuplicate(array, i, start);

            if(!duplicateFlag){
                swap(&array[start], &array[i]);
                permute(array, start+1, end);
                // After recursive call we swap our array back
                swap(&array[start], &array[i]);
            }
        }
    }
}

int main(){
    int array[] = {1,2,2,1};
    permute(array, 0, 3);
    return 0;
}