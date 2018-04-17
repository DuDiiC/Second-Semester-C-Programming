#include <stdio.h>
#include <stdlib.h>

int main() {
    char liczba[15];
    int liczbaInt;

    fgets(liczba, 15, stdin);
    while(liczba[0] != '-') {
        if(liczba[1] == 'x') {
            liczbaInt = strtol(liczba, NULL, 16);
            printf("%d\n", liczbaInt);
        } else {
            liczbaInt = strtol(liczba, NULL, 10);
            printf("0x%X\n", liczbaInt);
        }
        fgets(liczba, 15, stdin);
    }
    return 0;
}
