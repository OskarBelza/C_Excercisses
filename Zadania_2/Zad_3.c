#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point leftUpCorner;
    Point rightUpCorner;
    Point leftDownCorner;
    Point rightDownCorner;
} Rectangle;

void changePoint(Point *p){
    p->x++;
    p->y++;
}

int rectangleField(Rectangle rec){
    int lenA = rec.rightUpCorner.x - rec.leftUpCorner.x;
    int lenB = rec.leftUpCorner.y - rec.leftDownCorner.y;
    return lenA * lenB;
}

int rectangleCircuit(Rectangle rec){
    int lenA = rec.rightUpCorner.x - rec.leftUpCorner.x;
    int lenB = rec.leftUpCorner.y - rec.leftDownCorner.y;
    return 2*lenA + 2*lenB;
}

int main() {
    Point p;
    p.x = 5;
    p.y = 5;

    changePoint(&p);
    printf("Point x: %d Point y: %d\n", p.x, p.y);

    Point leftUp = {1,3};
    Point rightUp = {5,3};
    Point leftDown = {1,1};
    Point rightDown = {5,3};
    Rectangle rec = {leftUp, rightUp, leftDown, rightDown};

    printf("Field of rectangle: %d\n", rectangleField(rec));
    printf("Circuit of rectangle: %d\n", rectangleCircuit(rec));
    return 0;
}
