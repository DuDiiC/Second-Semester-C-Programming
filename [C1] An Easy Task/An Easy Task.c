#include <stdio.h>

int main(void) {
    int A1, B1, C1;
    int A2, B2, C2;
    double x, y;
    int wyznacznik, wyznacznikX, wyznacznikY;
    scanf("%d %d %d", &A1, &B1, &C1);
    scanf("%d %d %d", &A2, &B2, &C2);
    while(A1 != 0 || B1 != 0 || C1 != 0 || A2 != 0 || B2 != 0 || C2 != 0) {

        wyznacznik = A1*B2 - B1*A2;

        if(wyznacznik != 0) {

            wyznacznikX = C1*B2 - B1*C2;
            wyznacznikY = A1*C2 - C1*A2;

            x = (double)wyznacznikX/wyznacznik;
            y = (double)wyznacznikY/wyznacznik;
            if(x == 0) x = -x;
            if(y == 0) y = -y;

            printf("The fixed point is at %.2lf %.2lf.\n", x, y);

        } else {
            printf("No fixed point exists.\n");
        }

        scanf("%d %d %d", &A1, &B1, &C1);
        scanf("%d %d %d", &A2, &B2, &C2);
    }


    return 0;
}
