#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FOR(x, b, e) for(x = b; x <= (e); ++x) /* petla zwiekszajaca zmienna x od b do e wlacznie */
#define FORD(x, b, e) for(x = b; x >= (e); ––x) /* petla zmniejszajaca zmienna x od b do e wlacznie */
#define REP(x, n) for(x = 0; x < (n); ++x) /* petla zwiekszajaca x od 0 do n */

typedef long long LL;

const int INF = 1000000001;
const double EPS = 10e-9;

int main(void) {


    return 0;
}

/*
    przydatne funkcje z konkretnych zadan:
b1 - funkcja strtol zamienia lancuch znakow na liczbe w zadanym systemie liczbowym (biblioteka <stdlib.h>)
D2 - konwersja liczb z systemu BIN na DEC
e1 - dynamiczna alokacja , tutaj funkcja calloc(ilosc_blokow, rozmiar_bloku), potem free() na koncu
     osobno jest jeszcze funckja malloc(rozmiar_bloku)
F1 - fgets(lancuch, dlugosc, skad) - wczytuje do lancucha znakow ilosc znakow od uzytkownika
     strtok(skad, co_konczy) - ustawia wskaznik na pierwszy element w tablicy po tym co konczy
     (potrzebna biblioteka <string.h>)
F2 - strlen(lancuch) - oblicza dlugosc lancucha (biblioteka <string.h>)
G1 - isalpha(char) sprawdza czy znak jest litera w alfabecie angielskim,
     analogicznie dziala isdigit(char) dla cyfr, isspace(char) czy jest bialym znakiem
     (biblioteka <ctype.h>)
H2 - korzystanie z unii

    odpowiednie oznaczenia zmiennych w funkcjach printf(drukuj), scanf(wczytaj):
%d - int
%u - unsigned int
%llu - unsigned long long
%lf - double (%.xlf wypisuje double z dokladnoscia do x liczb po przecinku)
%s - lancuch znakow
%c - char

    binarne operacje:

*/
