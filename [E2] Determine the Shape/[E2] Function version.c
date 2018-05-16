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
    int dlugosc; /* zostawiam kwadrat => zostaje typ int */
    int A, B, C; /* wspolczynniki prostej Ax + By + C = 0 */
} Odcinek;

int dlugoscOdcinka(Punkt A, Punkt B); /**/

void wyliczWspolczynniki(Odcinek *prosta); /**/

void zamienPunkty(Punkt *A, Punkt *B); /**/

int gdziePunktC(Punkt A, Punkt B, Punkt C); /*?*/

int czySiePrzecinaja(Odcinek pierwszy, Odcinek drugi); /*?*/

int czyProstopadle(Odcinek pierwszy, Odcinek drugi); /*?*/

int czyRownolegle(Odcinek pierwszy, Odcinek drugi); /*?*/

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

    wyliczWspolczynniki(&prosta);

    printf("%d, %d, %d", prosta.A, prosta.B, prosta.C);

    return 0;
}

int dlugoscOdcinka(Punkt A, Punkt B) {
    int dlugosc;
    dlugosc = (B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y);
    return dlugosc;
}

void zamienPunkty(Punkt *A, Punkt *B) {
    Punkt temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

void wyliczWspolczynniki(Odcinek *prosta) {
    prosta->A = prosta->PunktA.y - prosta->PunktB.y;
    prosta->B = prosta->PunktB.x - prosta->PunktA.x;
    prosta->C = (prosta->PunktA.x * prosta->PunktB.y) - (prosta->PunktB.x * prosta->PunktA.y);
}

int gdziePunktC(Punkt A, Punkt B, Punkt C) {
    /*zwracam odpowiednio:
     *-1 gdy lezy po "lewej" stronie
     *0 gdy lezy na prostej
     *1 gdy lezy po "prawej" stronie
     */
    Odcinek prosta;
    int strona;

    prosta.PunktA = A;
    prosta.PunktB = B;
    wyliczWspolczynniki(&prosta);

    strona = prosta.A*C.x + prosta.B*C.y + prosta.C;
    if(strona < 0) return -1;
    if(strona == 0) return 0;
    return 1;
}

int czySiePrzecinaja(Odcinek pierwszy, Odcinek drugi) {
    /*0 jesli nie, 1 jesli tak*/
    if(pierwszy.A*drugi.A + pierwszy.B*drugi.B != 0) return 1;
    return 0;
}

int czyProstopadle(Odcinek pierwszy, Odcinek drugi) {
    /*0 jesli nie, 1 jesli tak*/
    if(pierwszy.A*drugi.A + pierwszy.B*drugi.B == 0) return 1;
    return 0;
}

int czyRownolegle(Odcinek pierwszy, Odcinek drugi) {
    /*0 jesli nie, 1 jesli tak*/
    if(pierwszy.A*drugi.B - drugi.A*pierwszy.B == 0) return 1;
    return 0;
}
