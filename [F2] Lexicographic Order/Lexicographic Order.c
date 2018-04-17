#include <stdio.h>
#include <stdlib.h>

int i, j, k;

unsigned long long fSilnia(int liczba);

int main(void) {

    int t;
    unsigned long long pozycja, silnia, indeks, pozycjaFaktyczna;
    int ktoraPermutacja[25], dlugoscSlowa, uzyte[25];
    char slowo[25], slowoKoncowe[25];

    scanf("%d", &t);

    for(i = 1; i <= t; ++i) {

        scanf("%s %llu", &slowo, &pozycja);

        /* nadawanie wartosci zmiennym */
        --pozycja; /* numeracja od 0 nie od 1 */
        dlugoscSlowa = strlen(slowo);
        silnia = fSilnia(dlugoscSlowa);
        for(j = 0; j < 25; ++j) uzyte[j] = 0;

        for(j = dlugoscSlowa; j > 0; --j) {

            /* mechanika znajdowania slow */
            indeks = 0;
            pozycjaFaktyczna = pozycja/(silnia/j);

            for(k = 0; k < dlugoscSlowa; ++k) {

                if(!uzyte[k] && indeks == pozycjaFaktyczna) {
                    indeks = k;
                    break;
                }
                if(!uzyte[k]) ++indeks;
            }

            uzyte[indeks] = 1;
            pozycja %= (silnia/j);
            silnia /= j;
            ktoraPermutacja[dlugoscSlowa-j] = indeks;

        }

        /* wypelnianie koncowego slowa */
        for(j = 0; j < dlugoscSlowa; ++j) {
            slowoKoncowe[ktoraPermutacja[j]] = slowo[j];
        }
        slowoKoncowe[dlugoscSlowa] = '\0';

        printf("Case %d: %s\n", i, slowoKoncowe);
    }

    return 0;
}

unsigned long long fSilnia(int liczba) {
    unsigned long long temp = 1;
    for(k = 1; k <= liczba; ++k) {
        temp *= k;
    }
    return temp;
}
