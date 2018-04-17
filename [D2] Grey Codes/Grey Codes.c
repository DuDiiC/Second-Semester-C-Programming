#include <stdio.h>
#include <math.h>

/* elementy w tablicy od najbardziej do najmniej znaczacego */
int binToDec(int tab[], int size) {
    int number = 0, i;
    for(i = size-1; i >= 0; --i) {
        if(tab[i] == 1) number += pow(2, (size-1-i));
    }
    return number;
}

int main(void) {
    int k;
    scanf("%d", &k);
    int i;
    for(i = 0; i < k; ++i) {
        int dlugosc, pozycja;
        scanf("%d %d", &dlugosc, &pozycja);
        int ilosc = pow(2, dlugosc);
        int tablicaBinarna[dlugosc];
        int j;
        int iloscJedynek = 0;
        for(j = 0; j < dlugosc; ++j) {
            if(pozycja < ilosc/2) {
                if(iloscJedynek%2 == 0) {
                    tablicaBinarna[j] = 0;
                } else if(iloscJedynek%2 == 1) {
                    tablicaBinarna[j] = 1;
                    ++iloscJedynek;
                }
                ilosc -= pow(2, (dlugosc-j-1));
            } else {
                if(iloscJedynek%2 == 0) {
                    tablicaBinarna[j] = 1;
                    ++iloscJedynek;
                } else if(iloscJedynek%2 == 1) {
                    tablicaBinarna[j] = 0;
                }
                ilosc += pow(2, (dlugosc-j-1));
            }
        }
        int koncowa = binToDec(tablicaBinarna, dlugosc);
        printf("%d\n", koncowa);
    }

    return 0;
}
