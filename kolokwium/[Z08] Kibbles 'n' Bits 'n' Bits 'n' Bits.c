#include <stdio.h>

int main(void) {
    int testy, i;
    unsigned int liczba1, liczba2, wynik;
    char binarnie1[] = "0000000000000";
    char binarnie2[] = "0000000000000";
    char znak;
    scanf("%d", &testy);

    while(testy--) {
        scanf("%x %c %x", &liczba1, &znak, &liczba2);
        if(znak == '+') wynik = liczba1+liczba2;
        else wynik = liczba1-liczba2;
        for(i = 0; i < 13; ++i) {
            binarnie1[i] = '0';
            binarnie2[i] = '0';
        }
        for(i = 12; i >= 0; i--) {
            if(liczba1 != 0) {
                if(liczba1%2 == 1) binarnie1[i] = '1';
            }
            if(liczba2 != 0) {
                if(liczba2%2 == 1) binarnie2[i] = '1';
            }
            liczba1 /= 2;
            liczba2 /= 2;
        }
        printf("%s %c %s = %d\n", binarnie1, znak, binarnie2, wynik);
    }
    return 0;
}
