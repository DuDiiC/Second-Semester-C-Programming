#include <stdio.h>

int main(void) {

    unsigned int number;
    int iterator;
    int numberSize;
    int tab[32] = {0};
    scanf("%u", &number);

    while(number != 0) {

        printf("The parity of ");
        iterator = 0;
        numberSize = 0;

        while(number != 0) {
            tab[numberSize] = number%2;
            if(tab[numberSize] == 1) ++iterator;
            ++numberSize;
            number /= 2;
        }

        while(numberSize--) printf("%d", tab[numberSize]);

        printf(" is %d (mod2).\n", iterator);

        scanf("%u", &number);

    }
}
