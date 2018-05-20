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

typedef struct Odcinek {
    Punkt PunktA;
    Punkt PunktB;
    int dlugosc; /* zostawiam kwadrat => zostaje typ int */
    int A, B, C; /* wspolczynniki prostej Ax + By + C = 0 */
} Odcinek;

void wczytajOdcinek(Odcinek *odcinek, Punkt A, Punkt B);

int dlugoscOdcinka(Punkt A, Punkt B);

void wyliczWspolczynniki(Odcinek *prosta);

void zamienPunkty(Punkt *A, Punkt *B);

int gdziePunktC(Punkt A, Punkt B, Punkt C);

int czySiePrzecinaja(Odcinek pierwszy, Odcinek drugi);

int czyProstopadle(Odcinek pierwszy, Odcinek drugi);

int czyRownolegle(Odcinek pierwszy, Odcinek drugi);

int main(void) {

    int testy, i;
    scanf("%d", &testy);

    for(i = 1; i <= testy; i++) {
        /*wczytanie danych*/
        Punkt pktA, pktB, pktC, pktD;
        Odcinek bok1, bok2, bok3, bok4;
        char *figura;

        scanf("%d %d", &pktA.x, &pktA.y);
        scanf("%d %d", &pktB.x, &pktB.y);
        scanf("%d %d", &pktC.x, &pktC.y);
        scanf("%d %d", &pktD.x, &pktD.y);

        wczytajOdcinek(&bok1, pktA, pktB);
        wczytajOdcinek(&bok2, pktB, pktC);
        wczytajOdcinek(&bok3, pktC, pktD);
        wczytajOdcinek(&bok4, pktD, pktA);

        /*logika wybierania*/
        if(bok1.dlugosc == bok3.dlugosc && bok2.dlugosc == bok4.dlugosc) {
            if(bok1.dlugosc == bok2.dlugosc) {
                if(czyProstopadle(bok1, bok2)) figura = KWADRAT;
                else figura = ROMB;
            } else {
                if(czyProstopadle(bok1, bok2) && czyProstopadle(bok3, bok4)) figura = PROSTOKAT;
                else figura = ROWNOLEGLOBOK;
            }
        } else if((czyRownolegle(bok1, bok3) && !czyRownolegle(bok2, bok4)) ||
                  (!czyRownolegle(bok1, bok3) && czyRownolegle(bok2, bok4))) {
                figura = TRAPEZ;
        } else figura = ZWYKLY;


        /*drukowanie wynikow*/
        printf("Case %d: %s\n", i, figura);
    }

    return 0;
}

void wczytajOdcinek(Odcinek *odcinek, Punkt A, Punkt B) {
    odcinek->PunktA = A;
    odcinek->PunktB = B;
    odcinek->dlugosc = dlugoscOdcinka(A, B);
    wyliczWspolczynniki(odcinek);
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
