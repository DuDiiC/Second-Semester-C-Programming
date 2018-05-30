#include <stdio.h>
int main(void) {

    int rozmiar;
    int macierz[101][101];
    int wiersze[101];
    int kolumny[101];
    int i, j;
    int ileBledowWierszy, ileBledowKolumn;
    int ktoryWiersz, ktoraKolumna;
    while(scanf("%d", &rozmiar) && rozmiar != 0) {
        for(i = 0; i < rozmiar; ++i) {
            wiersze[i] = 0;
            kolumny[i] = 0;
            for(j = 0; j < rozmiar; ++j)
                scanf("%d", &macierz[i][j]);
        }

        for(i = 0; i < rozmiar; ++i) {
            for(j = 0; j < rozmiar; ++j) {
                kolumny[i] += macierz[i][j];
                wiersze[i] += macierz[j][i];
            }
        }
        ileBledowWierszy = 0;
        ileBledowKolumn = 0;
        for(i = 0; i < rozmiar; ++i) {
            if(wiersze[i]%2 == 1) {
                ++ileBledowWierszy;
                ktoryWiersz = i;
            }
            if(kolumny[i]%2 == 1) {
                ++ileBledowKolumn;
                ktoraKolumna = i;
            }
        }

        if(ileBledowWierszy == 0 && ileBledowKolumn == 0) {
            printf("OK\n");
        } else if(ileBledowWierszy == 1 && ileBledowKolumn == 1) {
            printf("Change bit (%d,%d)\n", ktoraKolumna+1, ktoryWiersz+1);
        } else {
            printf("Corrupt\n");
        }
    }

    return 0;
}
