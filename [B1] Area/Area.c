#include <stdio.h>
#include <math.h>

double dlugosc_odcinka(double x1, double y1, double x2, double y2) {
    return pow(x2-x1, 2) + pow(y2-y1, 2);
}

int main(void) {

    long M, N, a;
    double x, y;
    double pole, pomoc;
    int i;
    double dlugosc1, dlugosc2, dlugosc3, dlugosc4;

    scanf("%ld %ld", &N, &a);

    while(N != 0) {
        M = 0;
        for(i = 0; i < N; ++i) {

            scanf("%lf %lf", &x, &y);

            dlugosc1 = dlugosc_odcinka(0, 0, x, y);
            dlugosc2 = dlugosc_odcinka(a, 0, x, y);
            dlugosc3 = dlugosc_odcinka(a, a, x, y);
            dlugosc4 = dlugosc_odcinka(0, a, x, y);

            if(dlugosc1 <= a*a && dlugosc2 <= a*a && dlugosc3 <= a*a && dlugosc4 <= a*a) {
                ++M;
            }
        }

        pomoc = M*a*a;
        pole = pomoc/N;

        printf("%.5lf\n", pole);

        scanf("%ld %ld", &N, &a);
    }

    return 0;
}
