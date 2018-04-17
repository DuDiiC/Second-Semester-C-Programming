#include <stdio.h>
#include <string.h>

int liczby[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70,
                80, 90, 100, 1000, 1000000};

int i;

char slowa[32][10] = {  "negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                        "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"};

int ktoryWyraz(char *tab) {
    char *wskNaNazwe;
    for(i = 0; i < 32; ++i) {
        wskNaNazwe = (char*)&(slowa[i]);
        if(strcmp(tab, wskNaNazwe) == 0) return i;
    }
    return 0;
}

int main(void) {

    char wiersz[400];
    char *nast;
    int ktory, j;
    int liczba, grupa[3] = {0, 0, 0}, ujemna = 0, pierwszy = 1;
    while(fgets(wiersz, 400, stdin) != NULL) {
        nast = (char*)strtok(wiersz, " \t\n");
        j = 0;
        while(nast != NULL) {
            ktory = ktoryWyraz(nast);
            if(ktory == 0) {
                ujemna = 1;
            } else if (ktory == 31 || ktory == 30 || ktory == 29) {
                if(pierwszy == 1) grupa[j] = 1;
                grupa[j] *= liczby[ktory];
                if(ktory != 29) pierwszy = 1;
                if(ktory != 29) ++j;
            } else {
                grupa[j] += liczby[ktory];
                pierwszy = 0;
            }

            nast = (char*)strtok(NULL, " \t\n");
        }
        liczba = grupa[0] + grupa[1] + grupa[2];
        if(ujemna == 1) printf("-");

        printf("%d\n", liczba);

        liczba = 0;
        for(i = 0; i < 3; ++i) grupa[i] = 0;
        ujemna = 0;
        j = 0;
        pierwszy = 1;
    }

    return 0;
}
