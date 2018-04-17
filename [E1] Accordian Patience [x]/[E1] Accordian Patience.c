#include <stdio.h>
#include <stdlib.h>

int numerStosu = 0;

/*trzeba jeszcze ogarnac ktora to karta*/

typedef struct {
    struct Wezel *nast;
    char kolor;
    char wartosc;
} Wezel;

typedef struct {
    Wezel *wierzch;
    int numer;
    int ileElementow;
} Stos;

void inicjuj(Stos *s) {
    s->wierzch = NULL;
    numerStosu++;
    s->numer = numerStosu;
    s->ileElementow = 0;
}

int pusty(Stos *s) {
    if(s->wierzch == NULL) return 1;
    else return 0;
}

void dodaj(Stos *s, char nowaWartosc, char nowyKolor) {
    Wezel *r = (Wezel*) malloc(sizeof(Wezel));
    r->kolor = nowyKolor;
    r->wartosc = nowaWartosc;
    r->nast = s->wierzch;
    s->wierzch = r;
    s->ileElementow += 1;
}

void zdejmij(Stos *s) {
    Wezel *r = s->wierzch;
    if(pusty(s) == 0) {
        r = s->wierzch->nast;
    }
    free(s->wierzch);
    s->wierzch = r;
    s->ileElementow -= 1;
}

char wierzchKolor(Stos *s) {
    if(pusty(s) == 0) return s->wierzch->kolor;
    else return '\0';
}

char wierzchWartosc(Stos *s) {
    if(pusty(s) == 0) return s->wierzch->wartosc;
    else return '\0';
}

int ktoryStos(Stos *s) {
    return s->numer;
}

int ileElementowNaStosie(Stos *s) {
    return s->ileElementow;
}

void zniszcz(Stos *s) {
    Wezel *r = s->wierzch;
    while(r != NULL) {
        r = r->nast;
        free(s->wierzch);
        s->wierzch = r;
    }
}

int main(void) {

    char dane[3];
    Stos *stos = (Stos*)calloc(53, sizeof(Stos));
    int i, j, czyNowy, naKtory;

    /*wczytanie danych*/
    while(scanf("%2s", dane) && dane[0] != '#') {
        /*pierwszy element*/
        inicjuj(stos);
        dodaj(stos, dane[0], dane[1]);

        /*pozostale elementy*/
        for(i = 1; i < 52; ++i) {
            scanf("%2s", dane);
            czyNowy = 1;
            /*mechanika odkladania*/

        }


        /*wypisanie danych*/
        if(numerStosu == 1) printf("1 pile remaining: 52\n");
        else {
            printf("%d piles remaining: ", numerStosu+1);
            for(i = 0; i < numerStosu; ++i) {
                printf("%d ", stos[i].ileElementow);
            }
            printf("\n");
        }

        for(i = 0; i < numerStosu; ++i) {
            zniszcz(stos);
        }
    }

    free(stos);

    return 0;
}

/*
    //TEST WCZYTYWANIA I ZDEJMOWANIA DANYCH, TAK JAK JEST TUTAJ, JEST POPRAWNIE

    Stos *stos = (Stos*)malloc(sizeof(Stos));
    inicjuj(stos);
    char dane[3]; //musze zostawic miejsce na znak konca napisu

    scanf("%2s", dane);
    dodaj(stos, dane[0], dane[1]);
    printf("%c, %c, %d, %d\n", wierzchKolor(stos), wierzchWartosc(stos), ktoryStos(stos), ileElementowNaStosie(stos));

    scanf("%2s", dane);
    dodaj(stos, dane[0], dane[1]);
    printf("%c, %c, %d, %d\n", wierzchKolor(stos), wierzchWartosc(stos), ktoryStos(stos), ileElementowNaStosie(stos));

    zdejmij(stos);
    printf("%c, %c, %d, %d\n", wierzchKolor(stos), wierzchWartosc(stos), ktoryStos(stos), ileElementowNaStosie(stos));


    zniszcz(stos);
    free(stos);
*/
