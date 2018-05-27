#include <stdio.h>
#ifndef PUNKT
    #define PUNKT 1

    typedef struct Punkt {
        int x;
        int y;
    } Punkt;

    int dlugoscOdcinka(Punkt A, Punkt B);

    void zamienPunkty(Punkt *A, Punkt *B);

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
#endif /* PUNKT */
