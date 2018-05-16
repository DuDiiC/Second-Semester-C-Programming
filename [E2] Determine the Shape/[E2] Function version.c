#include <stdio.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct LineSegment {
    Point pointA;
    Point pointB;
    int length; /* squared, because it will be Integer */
    int A, B, C; /* coefficients of the general form of a square function */
} LineSegment;

int lineSegmentLength(Point A, Point B); /**/

void coefficients(LineSegment *line); /**/

void changePoints(Point *A, Point *B); /**/

int whereIsPointC(Point A, Point B, Point C); /*?*/

int lineSegmentIntsect(LineSegment first, LineSegment second);

int perpendicularLines(LineSegment first, LineSegment second);

int parallelLines(LineSegment first, LineSegment second);

int main(void) {

    Point pierwszy;
    Point drugi;
    pierwszy.x = 2;
    pierwszy.y = 5;
    drugi.x = 5;
    drugi.y = 9;

    LineSegment prosta;
    prosta.pointA = pierwszy;
    prosta.pointB = drugi;

    coefficients(&prosta);

    printf("%d, %d, %d", prosta.A, prosta.B, prosta.C);

    return 0;
}

int lineSegmentLength(Point A, Point B) {
    int length;
    length = (B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y);
    return length;
}

void changePoints(Point *A, Point *B) {
    Point temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

void coefficients(LineSegment *line) {
    line->A = line->pointA.y - line->pointB.y;
    line->B = line->pointB.x - line->pointA.x;
    line->C = (line->pointA.x * line->pointB.y) - (line->pointB.x * line->pointA.y);
}

int whereIsPointC(Point A, Point B, Point C) {
    /*zwracam odpowiednio:
     *-1 gdy lezy po "lewej" stronie
     *0 gdy lezy na
     *1 gdy lezy po "prawej" stronie
     */
    LineSegment line;
    int side;

    line.pointA = A;
    line.pointB = B;
    coefficients(&line);

    side = line.A*C.x + line.B*C.y + line.C;
    if(side < 0) return -1;
    if(side == 0) return 0;
    return 1;
}

int lineSegmentIntsect(LineSegment first, LineSegment second) {
    /*sprawdza czy dwa odcinki sie przecinaja, 0 jesli nie, 1 jesli tak*/
    return 0;
}

int perpendicularLines(LineSegment first, LineSegment second) {
    /*sprawdza czy dwa odcinki sa prostopadle, 0 jesli nie, 1 jesli tak*/
    return 0;
}

int parallelLines(LineSegment first, LineSegment second) {
    /*sprawdza czy dwa odcinki sa rownolegle, 0 jesli nie, 1 jesli tak*/
    return 0;
}
