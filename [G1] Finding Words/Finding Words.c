#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {

    char linia[61];
    fgets(linia, 60, stdin);
    while(strlen(linia) != 2 || linia[0] != '#') {

        char *slowo =

        printf("%s\n", linia);


        fgets(linia, 60, stdin);
    }

    return 0;
}
