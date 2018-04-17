#include <stdio.h>

struct Wektor {
        double a, b;
};

int main(void) {

    double x1, x2, x3, x4, y1, y2, y3, y4;
    double xk, yk;
    struct Wektor wektor[3];

    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != -1) {

        if(x1 == x3 && y1 == y3) {

            wektor[0].a = x2 - x1;
            wektor[0].b = y2 - y1;
            wektor[1].a = x4 - x3;
            wektor[1].b = y4 - y3;
            wektor[2].a = wektor[0].a + wektor[1].a;
            wektor[2].b = wektor[0].b + wektor[1].b;

            xk = x1 + wektor[2].a;
            yk = y1 + wektor[2].b;

        } else if(x1 == x4 && y1 == y4) {

            wektor[0].a = x2 - x1;
            wektor[0].b = y2 - y1;
            wektor[1].a = x3 - x4;
            wektor[1].b = y3 - y4;
            wektor[2].a = wektor[0].a + wektor[1].a;
            wektor[2].b = wektor[0].b + wektor[1].b;

            xk = x1 + wektor[2].a;
            yk = y1 + wektor[2].b;

        } else if(x2 == x3 && y2 == y3) {

            wektor[0].a = x1 - x2;
            wektor[0].b = y1 - y2;
            wektor[1].a = x4 - x3;
            wektor[1].b = y4 - y3;
            wektor[2].a = wektor[0].a + wektor[1].a;
            wektor[2].b = wektor[0].b + wektor[1].b;

            xk = x2 + wektor[2].a;
            yk = y2 + wektor[2].b;

        } else if(x2 == x4 && y2 == y4) {

            wektor[0].a = x1 - x2;
            wektor[0].b = y1 - y2;
            wektor[1].a = x3 - x4;
            wektor[1].b = y3 - y4;
            wektor[2].a = wektor[0].a + wektor[1].a;
            wektor[2].b = wektor[0].b + wektor[1].b;

            xk = x2 + wektor[2].a;
            yk = y2 + wektor[2].b;

        }

        printf("%.3lf %.3lf\n", xk, yk);

    }
    return 0;
}
