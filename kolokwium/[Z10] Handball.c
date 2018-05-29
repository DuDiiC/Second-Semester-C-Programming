#include <stdio.h>

int main(void) {
    int N, M, i, j;
    int zawodnik[110];
    int liczba;
    int ilu;
    while(scanf("%d %d", &N, &M) == 2) {
        ilu = 0;
        for(i = 0; i < N; ++i) {
            zawodnik[i] = 1;
        }
        for(i = 0; i < N; ++i) {
            for(j = 0; j < M; ++j) {
                scanf("%d", &liczba);
                if(liczba == 0) zawodnik[i] = 0;
            }
        }
        for(i = 0; i < N; ++i) {
            if(zawodnik[i] == 1) ++ilu;
        }

        printf("%d\n", ilu);

    }

    return 0;
}
