#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char *name;
    float grade;
} Student;

void swap(Student *pStud1, Student *pStud2){
    Student temp = *pStud1;
    *pStud1 = *pStud2;
    *pStud2 = temp;
}

void bubbleSort(Student students[], int n){
    bool swapped;
    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n-1; j++){
            if(students[j].grade > students[j+1].grade){
                swapped = true;
                swap(&students[j], &students[j+1]);
            }
        }
        if(swapped == false){
            break;
        }
    }
}

int main() {
    Student students[] = {
            {"Balon", 4.2f},
            {"Wajcha", 4.6f},
            {"Grzesiu", 4.4f},
            {"Oskar", 4.9f},
            {"Jakub", 4.0f}
    };
    int arrayLen = sizeof (students)/sizeof (students[0]);
    bubbleSort(students, arrayLen);
    for(int i = 0; i < arrayLen; i++){
        printf("Student %s: %.2f\n", students[i].name, students[i].grade);
    }
    return 0;
}
