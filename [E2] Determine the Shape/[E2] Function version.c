#include <stdio.h>

#define KWADRAT "Square"
#define PROSTOKAT "Rectangle"
#define ROMB "Rhombus"
#define ROWNOLEGLOBOK "Parallelogram"
#define TRAPEZ "Trapezium"
#define ZWYKLY "Ordinary Quadrilateral"

typedef struct Punkt {
    int x;
    int y;
} Punkt;

typedef struct Odcniek {
    Punkt PunktA;
    Punkt PunktB;
    int length; /* squared, because it will be Integer */
    int A, B, C; /* coefficients of the general form of a square function */
} Odcinek;

int lineSegmentLength(Punkt A, Punkt B); /**/

void coefficients(Odcinek *line); /**/

void changePoints(Punkt *A, Punkt *B); /**/

int whereIsPointC(Punkt A, Punkt B, Punkt C); /*?*/

int lineSegmentIntsect(Odcinek first, Odcinek second);

int perpendicularLines(Odcinek first, Odcinek second);

int parallelLines(Odcinek first, Odcinek second);

int main(void) {

    Punkt pierwszy;
    Punkt drugi;
    pierwszy.x = 2;
    pierwszy.y = 5;
    drugi.x = 5;
    drugi.y = 9;

    Odcinek prosta;
    prosta.PunktA = pierwszy;
    prosta.PunktB = drugi;

    coefficients(&prosta);

    printf("%d, %d, %d", prosta.A, prosta.B, prosta.C);

    return 0;
}

int lineSegmentLength(Punkt A, Punkt B) {
    int length;
    length = (B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y);
    return length;
}

void changePoints(Punkt *A, Punkt *B) {
    Punkt temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

void coefficients(Odcinek *line) {
    line->A = line->PunktA.y - line->PunktB.y;
    line->B = line->PunktB.x - line->PunktA.x;
    line->C = (line->PunktA.x * line->PunktB.y) - (line->PunktB.x * line->PunktA.y);
}

int whereIsPointC(Punkt A, Punkt B, Punkt C) {
    /*zwracam odpowiednio:
     *-1 gdy lezy po "lewej" stronie
     *0 gdy lezy na
     *1 gdy lezy po "prawej" stronie
     */
    Odcinek line;
    int side;

    line.PunktA = A;
    line.PunktB = B;
    coefficients(&line);

    side = line.A*C.x + line.B*C.y + line.C;
    if(side < 0) return -1;
    if(side == 0) return 0;
    return 1;
}

int lineSegmentIntsect(Odcinek first, Odcinek second) {
    /*sprawdza czy dwa odcinki sie przecinaja, 0 jesli nie, 1 jesli tak*/
    return 0;
}

int perpendicularLines(Odcinek first, Odcinek second) {
    /*sprawdza czy dwa odcinki sa prostopadle, 0 jesli nie, 1 jesli tak*/
    return 0;
}

int parallelLines(Odcinek first, Odcinek second) {
    /*sprawdza czy dwa odcinki sa rownolegle, 0 jesli nie, 1 jesli tak*/
    return 0;
}
