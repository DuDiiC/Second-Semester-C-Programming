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

int gdziePunktC(Punkt A, Punkt B, Punkt C); /**/

int czySiePrzecinaja(Odcinek pierwszy, Odcinek drugi); /**/

int czyProstopadle(Odcinek pierwszy, Odcinek drugi); /**/

int czyRownolegle(Odcinek pierwszy, Odcinek drugi); /**/

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

    /*-------*/

    Punkt pierwszy2;
    Punkt drugi2;
    pierwszy2.x = 0;
    pierwszy2.y = 3;
    drugi2.x = 3;
    drugi2.y = 7;

    Odcinek prosta2;
    prosta2.PunktA = pierwszy2;
    prosta2.PunktB = drugi2;

    wyliczWspolczynniki(&prosta2);

    /*-------*/

    Punkt pierwszy3;
    Punkt drugi3;
    pierwszy3.x = 0;
    pierwszy3.y = 1;
    drugi3.x = -4;
    drugi3.y = 4;

    Odcinek prosta3;
    prosta3.PunktA = pierwszy3;
    prosta3.PunktB = drugi3;

    wyliczWspolczynniki(&prosta3);

    /*-------*/

    Punkt pierwszy4;
    Punkt drugi4;
    pierwszy4.x = 0;
    pierwszy4.y = 3;
    drugi4.x = 5;
    drugi4.y = 1;

    Odcinek prosta4;
    prosta4.PunktA = pierwszy4;
    prosta4.PunktB = drugi4;

    wyliczWspolczynniki(&prosta4);

    /*-------*/

    Punkt C1, C2, C3, C4, C5;
    C1.x = 7; C1.y = 4;
    C2.x = 2; C2.y = 1;
    C3.x = 0; C3.y = 5;
    C4.x = -2; C4.y = 1;
    C5.x = -4; C5.y = -3;

    /*-------*/

    printf("Czy rownolegle pierwsza z druga: %d\nPierwsza z trzecia: %d\nPierwsza z czwarta: %d\n", czyRownolegle(prosta, prosta2), czyRownolegle(prosta, prosta3), czyRownolegle(prosta, prosta4));
    printf("Czy prostopadle pierwsza z druga: %d\nPierwsza z trzecia: %d\nPierwsza z czwarta: %d\n", czyProstopadle(prosta, prosta2), czyProstopadle(prosta, prosta3), czyProstopadle(prosta, prosta4));
    printf("Czy sie przecinaja pierwsza z druga: %d\nPierwsza z trzecia: %d\nPierwsza z czwarta: %d\n", czySiePrzecinaja(prosta, prosta2), czySiePrzecinaja(prosta, prosta3), czySiePrzecinaja(prosta, prosta4)); /* LE */
    printf("Punkt lezy: %d, %d, %d, %d, %d", gdziePunktC(prosta.PunktA, prosta.PunktB, C1), gdziePunktC(prosta.PunktA, prosta.PunktB, C2), gdziePunktC(prosta.PunktA, prosta.PunktB, C3), gdziePunktC(prosta.PunktA, prosta.PunktB, C4), gdziePunktC(prosta.PunktA, prosta.PunktB, C5));

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

/* sposob implementacji kolejnych funkcji, opieralem na informacjach ze zrodel:
 * http://www.math.us.edu.pl/pgladki/faq/node102.html
 * http://www.math.edu.pl/wzajemne-polozenie-prostych
 */

int gdziePunktC(Punkt A, Punkt B, Punkt C) {
    /*zwracam odpowiednio:
     *-1 gdy lezy po "prawej" stronie
     *0 gdy lezy na prostej
     *1 gdy lezy po "lewej" stronie
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
    if(pierwszy.A*drugi.B - drugi.A*pierwszy.B != 0) return 1;
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
