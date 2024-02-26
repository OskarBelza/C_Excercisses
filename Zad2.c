#include <stdlib.h>
#include <stdio.h>

int main2(){
    int grades[2][5] = {{2,3,4,3,4},{5,4,3,2,4}};
    int sumPhysics = 0;
    int sumMathematics = 0;
    int gradesCount = sizeof(grades[0]) / sizeof(grades[0][0]);

    for(int i = 0; i < gradesCount; i++){
        sumMathematics += grades[0][i];
        sumPhysics += grades[1][i];
    }

    float meanMathematics = (float) sumMathematics/gradesCount;
    float meanPhysics = (float) sumPhysics/gradesCount;

    printf("Grade point average in mathematics: %.2f\n", meanMathematics);
    printf("Grade point average in physics: %.2f", meanPhysics);

    return 0;
}