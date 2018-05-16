#include <stdio.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct lineSegment {
    Point point;
    int length; /* squared, because it will be Integer */
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

int lineSegmentLength(Point A, Point B) {
    int length;

    length = (B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y);

    return length;
}

int main(void) {

/*test*/
    Point pierwszy;
    Point drugi;
    pierwszy.x = 2;
    pierwszy.y = 5;
    drugi.x = 5;
    drugi.y = 9;

    printf("Dlugosc odcinka do kwadratu to: %d", lineSegmentLength(pierwszy, drugi));

    return 0;
}
