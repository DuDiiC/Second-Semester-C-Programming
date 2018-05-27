#include "punkty.c"

#ifndef ODCINEK
    #define ODCINEK 1

    typedef struct Odcinek {
        Punkt PunktA;
        Punkt PunktB;
        int dlugosc; /* zostawiam kwadrat => zostaje typ int */
        int A, B, C; /* wspolczynniki prostej Ax + By + C = 0 */
    } Odcinek;

    void wczytajOdcinek(Odcinek *odcinek, Punkt A, Punkt B);

    void wyliczWspolczynniki(Odcinek *prosta);

    int gdziePunktC(Punkt A, Punkt B, Punkt C);

    int czySiePrzecinaja(Odcinek pierwszy, Odcinek drugi);

    int czyProstopadle(Odcinek pierwszy, Odcinek drugi);

    int czyRownolegle(Odcinek pierwszy, Odcinek drugi);

    void wczytajOdcinek(Odcinek *odcinek, Punkt A, Punkt B) {
        odcinek->PunktA = A;
        odcinek->PunktB = B;
        odcinek->dlugosc = dlugoscOdcinka(A, B);
        wyliczWspolczynniki(odcinek);
    }

    void wyliczWspolczynniki(Odcinek *prosta) {
        prosta->A = prosta->PunktA.y - prosta->PunktB.y;
        prosta->B = prosta->PunktB.x - prosta->PunktA.x;
        prosta->C = (prosta->PunktA.x * prosta->PunktB.y) - (prosta->PunktB.x * prosta->PunktA.y);
    }

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
#endif /* ODCINEK */
