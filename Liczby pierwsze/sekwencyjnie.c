#include<stdio.h>
#include<math.h>

int max;

void czyPierwsza() {
    int testowa = max;
    int i, czyPierwsza = 1;

    max++;


    for(i = 2 ; i*i <= testowa; ++i) {
        if(testowa%i == 0 && testowa != 2) {
            czyPierwsza = 0;
            break;
        }
    }
    if(czyPierwsza == 1);
       /*  printf("%d\n", testowa); */
}

int main(void) {
    max = 2;
    while(max < pow(10, 8)) {
        czyPierwsza();
    }
    return 0;
}
