#ifndef PUNKT
    #include "punkty.c"
#endif /* PUNKT */
#ifndef ODCINEK
    #include "odcinki.c"
#endif /* ODCINEK */

#define KWADRAT "Square"
#define PROSTOKAT "Rectangle"
#define ROMB "Rhombus"
#define ROWNOLEGLOBOK "Parallelogram"
#define TRAPEZ "Trapezium"
#define ZWYKLY "Ordinary Quadrilateral"


int main(void)
{
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

        /*zamiana kolejnosci punktow*/

        if(gdziePunktC(pktA, pktB, pktC) == gdziePunktC(pktA, pktB, pktD)) {

            Odcinek pierwszy, drugi;
            wczytajOdcinek(&pierwszy, pktA, pktD);
            wczytajOdcinek(&drugi, pktB, pktC);

            if(czySiePrzecinaja(pierwszy, drugi))
                zamienPunkty(&pktC, &pktD);

        } else zamienPunkty(&pktB, &pktC);

        /*obliczanie parametrow odcinkow*/
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
