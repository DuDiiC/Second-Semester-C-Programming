#include <stdio.h>

int main(void) {
    int i, N;
    int x1, y1, x2, y2, x3, y3;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {

        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

        if((y3-y1)*(x2-x1) == (x3-x1)*(y2-y1)) printf("TAK\n");
        else printf("NIE\n");
    }

    return 0;
}
