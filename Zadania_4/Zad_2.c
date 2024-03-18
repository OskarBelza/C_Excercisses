#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int leftIndex, int rightIndex, int searchValue){
    // Condition to end search when value doesn't exist in array
    if (leftIndex > rightIndex){
        return -1;
    }
    else{
        // Check if middle value is our search value
        int middleIndex = (leftIndex+rightIndex)/2;

        if (array[middleIndex] == searchValue){
            return middleIndex;
        }
        // If not, split the array in half and call recursive function to right half
        else if (searchValue < array[middleIndex]){
            return binarySearch(array, leftIndex, middleIndex-1, searchValue);
        }
        else{
            return binarySearch(array,middleIndex+1, rightIndex, searchValue);
        }
    }
}

int main(){
    int sortedArray[] = {1,2,4,6,7,8};
    int index = binarySearch(sortedArray, 0, 5, 8);
    if (index == -1){
        printf("Value not found\n");
    } else{
        printf("Index of our value in array is: %d\n", index);
    }
    return 0;
}