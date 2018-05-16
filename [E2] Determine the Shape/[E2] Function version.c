#include <stdio.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct lineSegment {
    Point point;
    double length;
} lineSegment;

void changePoints(Point *A, Point *B) {
    Point temp;

    temp = *A;
    *A = *B;
    *B = temp;
}

int whereIsPointC(Point A, Point B, Point C) {
    /*zwracam odpowiednio:
     *-1 gdy lezy na lewym krancu
     *0 gdy lezy pomiedzy
     *1 gdy lezy na prawym krancu
     */
    return 0;
}

int lineSegmentIntsect(lineSegment first, lineSegment second) {
    /*sprawdza czy dwa odcinki sie przecinaja, 0 jesli nie, 1 jesli tak*/
    return 0;
}

int perpendicularLines(lineSegment first, lineSegment second) {
    /*sprawdza czy dwa odcinki sa prostopadle, 0 jesli nie, 1 jesli tak*/
    return 0;
}

int parallelLines(lineSegment first, lineSegment second) {
    /*sprawdza czy dwa odcinki sa rownolegle, 0 jesli nie, 1 jesli tak*/
    return 0;
}

double lineSegmentLength(Point A, Point B) {
    /*liczy dlugosc odcinka*/
    double length;

    return length;
}

int main(void) {


    return 0;
}
