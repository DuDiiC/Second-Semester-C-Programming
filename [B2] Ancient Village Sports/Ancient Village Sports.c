#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int N, licznik = 0;
    double P, Ptrojkat, r2, R2;
    double alfa, beta;
    double Pwpisanego, Popisanego;
    double Pduze, Pmale;
    double PI = 2*acos(0);
    scanf("%d %lf", &N, &P);

    while(N >= 3) {
        ++licznik;

        Ptrojkat = P/(2*N);

        alfa = PI/N;
        beta = (PI/2)-alfa;

        r2 = 2 * Ptrojkat * sin(beta) / sin(alfa);
        R2 = (2 * Ptrojkat) / (sin(alfa) * sin(beta));

        Pwpisanego = PI * r2;
        Popisanego = PI * R2;

        Pduze = Popisanego - P;
        Pmale = P - Pwpisanego;

        printf("Case %d: %.5lf %.5lf\n", licznik, Pduze, Pmale);
        scanf("%d %lf", &N, &P);
    }


    return 0;
}
