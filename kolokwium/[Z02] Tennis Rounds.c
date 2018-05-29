#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rundy, nr1, nr2, nrRundy;
    while(scanf("%d %d %d", &rundy, &nr1, &nr2) == 3) {
        nrRundy = 1;
        if(nr1 > nr2) {
            int temp = nr1;
            nr1 = nr2;
            nr2 = temp;
        }
        while(!(nr1%2 == 1 && nr2==nr1+1)) {
            nrRundy++;
            nr1 = (int)ceil((double)nr1/2);
            nr2 = (int)ceil((double)nr2/2);
        }

        printf("%d\n", nrRundy);

    }
    return 0;
}
