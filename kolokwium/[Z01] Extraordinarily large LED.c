#include <stdio.h>

int ileSwieci[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; /* dla kazdej cyfry od 0 do 9 */

int zuzycieEnergiiNaSekunde(int punkty);

int main(void) {

    int numerTestu = 1;
    int godzina, minuta, sekunda, czasPoczatkowy, czasAktualny;
    char slowo[10];
    int punktyGospodarzy, punktyGosci, wczytanePunkty;
    int koncoweZuzycieEnergii;

    while(scanf("%*s") == 0) { /* oznacza pominiêcie wczytywania napisu, to jest wczytanie START */

        /* resetowanie zmiennych */
        scanf("%d:%d:%d", &godzina, &minuta, &sekunda);
        czasPoczatkowy = 3600*godzina + 60*minuta + sekunda; /* w sekundach */
        punktyGospodarzy = 0;
        punktyGosci = 0;
        koncoweZuzycieEnergii = 0;

        while(scanf("%s", slowo) == 1) { /*wczytywanie danych */
            scanf("%d:%d:%d", &godzina, &minuta, &sekunda);
            czasAktualny = 3600*godzina + 60*minuta + sekunda;
            /* dodajemy zuzycie energii od poprzedniego stanu do aktualnego */
            koncoweZuzycieEnergii += (zuzycieEnergiiNaSekunde(punktyGospodarzy) + zuzycieEnergiiNaSekunde(punktyGosci)) * (czasAktualny - czasPoczatkowy);

            if(slowo[0] == 'E') break; /* sprawdzam czy END */
            else { /* jak nie to wczytuje dalej dane o punktach */
                scanf("%s %d", slowo, &wczytanePunkty);
                /* punkty dla gospodarzy czy dla kosci */
                if(slowo[0] == 'h') punktyGospodarzy += wczytanePunkty;
                else punktyGosci += wczytanePunkty;

                czasPoczatkowy = czasAktualny;
            }
        }
        printf("Case %d: %d\n", numerTestu, koncoweZuzycieEnergii);
        ++numerTestu;
    }
    return 0;
}

int zuzycieEnergiiNaSekunde(int punkty) {
    int cyfraPoboru;
    int zuzycieEnergii = 0;
    while(punkty > 0) {
        cyfraPoboru = punkty%10;
        punkty /= 10;
        zuzycieEnergii += ileSwieci[cyfraPoboru];
    }
    return zuzycieEnergii;
}
