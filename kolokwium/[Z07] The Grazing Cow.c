#include <stdio.h>
#include <math.h>

double pii = 2*acos(0);

int main(void) {
    int testy;
    scanf("%d", &testy);

    while(testy--) {
        double odleglosc, dlugoscLiny, a, b, pole;
        scanf("%lf %lf", &odleglosc, &dlugoscLiny);
        odleglosc /= 2;
        dlugoscLiny /= 2;
        a = dlugoscLiny;
        b = sqrt(a*a - odleglosc*odleglosc);
        pole = pii*a*b;
        printf("%.03lf\n", pole);
    }

    return 0;
}
