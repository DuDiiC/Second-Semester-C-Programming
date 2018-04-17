#include <stdio.h>
#include <math.h>

int main(void) {
    int licznik = 1;
    int n;
    while(scanf("%d", &n)) {
        if(n < 0) break;
        int temp = 1;
        int temp2 = 0;
        while(temp < n) {
            temp *= 2;
            temp2++;
        }

        printf("Case %d: %d\n", licznik, temp2);
        licznik++;
    }
    return 0;
}
