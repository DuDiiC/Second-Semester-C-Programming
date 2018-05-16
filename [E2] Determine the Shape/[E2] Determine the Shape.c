#include <stdio.h>
#include <math.h>

char kwadrat[] = "Square";
char prostokat[] = "Rectangle";
char romb[] = "Rhombus";
char rownoleglobok[] = "Parallelogram";
char trapez[] = "Trapezium";
char zwykly[] = "Ordinary Quadrilateral";

void zamien(int *zmienna1, int *zmienna2);

void ustalKolejnosc(int tabX[4], int tabY[4]);

int czyTrapez(int tabX[4], int tabY[4]);

int jakaFigura(int boki[4], int przekat1, int przekat2, int tabX[4], int tabY[4]);

void wypisz(int caseI, int fig);

int main(void) {

    int cases, i;
    scanf("%d", &cases);

    int x[4], y[4], bok[4], przekatna1, przekatna2, figura;
    for(i = 1; i <= cases; ++i) {

        scanf("%d %d", &x[0], &y[0]);
        scanf("%d %d", &x[1], &y[1]);
        scanf("%d %d", &x[2], &y[2]);
        scanf("%d %d", &x[3], &y[3]);

        ustalKolejnosc(x, y);

        bok[0] = (int)(pow(x[0]-x[1], 2) + pow(y[0]-y[1], 2));
        bok[1] = (int)(pow(x[1]-x[2], 2) + pow(y[1]-y[2], 2));
        bok[2] = (int)(pow(x[2]-x[3], 2) + pow(y[2]-y[3], 2));
        bok[3] = (int)(pow(x[3]-x[0], 2) + pow(y[3]-y[0], 2));
        przekatna1 = (int)(pow(x[0]-x[2], 2) + pow(y[0]-y[2], 2));
        przekatna2 = (int)(pow(x[1]-x[3], 2) + pow(y[1]-y[3], 2));
        /*zostawiam jako "kwadraty", zeby uniknac ulamkow*/

        figura = jakaFigura(bok, przekatna1, przekatna2, x, y);

        wypisz(i, figura);
    }

    return 0;
}

void zamien(int *zmienna1, int *zmienna2) {
    int temp = *zmienna1;
    *zmienna1 = *zmienna2;
    *zmienna2 = temp;
}

void ustalKolejnosc(int tabX[4], int tabY[4]) {

    int pomoc1 = ((tabX[2]-tabX[0])*(tabY[0]-tabY[1])+(tabY[2]-tabY[0])*(tabX[1]-tabX[0]));
    int pomoc2 = ((tabX[3]-tabX[0])*(tabY[0]-tabY[1])+(tabY[3]-tabY[0])*(tabX[1]-tabX[0]));

    if((pomoc1 > 0 && pomoc2 < 0) || (pomoc1 < 0 && pomoc2 > 0)) {
        zamien(&tabX[1], &tabX[2]);
        zamien(&tabY[1], &tabY[2]);
    } else {

        pomoc1 = ((tabX[1]-tabX[0])*(tabY[0]-tabY[3])+(tabY[1]-tabY[0])*(tabX[3]-tabX[0]));
        pomoc2 = ((tabX[2]-tabX[0])*(tabY[0]-tabY[3])+(tabY[2]-tabY[0])*(tabX[3]-tabX[0]));

        if((pomoc1 > 0 && pomoc2 < 0) || (pomoc1 < 0 && pomoc2 > 0)) {
            zamien(&tabX[2], &tabX[3]);
            zamien(&tabY[2], &tabY[3]);
        }
    }
}

int czyTrapez(int tabX[4], int tabY[4]) {
    int pomocX1, pomocY1, pomocX2, pomocY2;
    pomocX1 = tabX[0]-tabX[1];
    pomocY1 = tabY[0]-tabY[1];
    pomocX2 = tabX[2]-tabX[3];
    pomocY2 =tabY[2]-tabY[3];

    if((pomocX2*pomocY1) == (pomocX1*pomocY2)) return 1;
    else {
        pomocX1 = tabX[1]-tabX[2];
        pomocY1 = tabY[1]-tabY[2];
        pomocX2 = tabX[3]-tabX[0];
        pomocY2 = tabY[3]-tabY[0];
        if((pomocX2*pomocY1) == (pomocX1*pomocY2)) return 1;
        else return 0;
    }
}

int jakaFigura(int boki[4], int przekat1, int przekat2, int tabX[4], int tabY[4]) {
    if(boki[0] == boki[2] && boki[1] == boki[3]) {
        if(boki[0] == boki[1]) {
            if(przekat1 == przekat2) return 1; /*kwadrat*/
            else return 3; /*romb*/
        } else {
            if(przekat1 == przekat2) return 2; /*prostokat*/
            else return 4; /*rownoleglobok*/
        }
    } else if(czyTrapez(tabX, tabY)) {
        return 5; /*trapez*/
    } else return 6; /*cos innego*/
}

void wypisz(int caseI, int fig) {
    printf("Case %d: ", caseI);
    switch(fig) {
    case 1:
        printf("%s\n", kwadrat);
        break;
    case 2:
        printf("%s\n", prostokat);
        break;
    case 3:
        printf("%s\n", romb);
        break;
    case 4:
        printf("%s\n", rownoleglobok);
        break;
    case 5:
        printf("%s\n", trapez);
        break;
    case 6:
        printf("%s\n", zwykly);
    }
}
