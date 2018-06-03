#include <stdio.h>

#define FOR(x, b, e) for(x = b; x <= (e); ++x)
#define FORD(x, b, e) for(x = b; x >= (e); ––x)
#define REP(x, n) for(x = 0; x < (n); ++x)

typedef struct Stack {
    int x;
    int y;
} Stack;

int main(void) {

    int i, j, k;
    char card[3];
    Stack s[52][52];
    int tops[52];
    int howMuch;
    int yesOrNo;

    while(scanf("%s", card) && card[0] != '#') { /* loading the first card */

        s[0][0].x = card[0];
        s[0][0].y = card[1];

        FOR(i, 1, 51) { /* loading of other cards */
            scanf("%s", card);
            s[i][0].x = card[0];
            s[i][0].y = card[1];
        }

        REP(i, 52) tops[i] = 0;
        howMuch = 52;

        while(1) {
            yesOrNo = 0;
            REP(i, howMuch) {
                /* fits three befofe */
                if(i >= 3 && (s[i][tops[i]].x == s[i-3][tops[i-3]].x ||
                              s[i][tops[i]].y == s[i-3][tops[i-3]].y)) {
                    /* change position of card */
                    tops[i-3]++;
                    s[i-3][tops[i-3]] = s[i][tops[i]];
                    tops[i]--;
                    yesOrNo = 1;
                } /*fits one before */
                else if(i >= 1 && (s[i][tops[i]].x == s[i-1][tops[i-1]].x ||
                                   s[i][tops[i]].y == s[i-1][tops[i-1]].y)) {
                    /* change position of card */
                    tops[i-1]++;
                    s[i-1][tops[i-1]] = s[i][tops[i]];
                    tops[i]--;
                    yesOrNo = 1;
                }

                if(tops[i] == -1) {
                    FOR(j, i+1, howMuch-1) {
                        REP(k, tops[j]+1) {
                            s[j-1][k] = s[j][k];
                        }
                        tops[j-1] = tops[j];
                    }
                    howMuch--;
                }
                if(yesOrNo == 1) break;
            }
            if(!yesOrNo) break;
        }
        /* output */
        if(howMuch-1 == 0) {
            printf("%d pile remaining: ", howMuch);
        } else {
            printf("%d piles remaining: ", howMuch);
        }
        REP(i, howMuch) {
            printf("%d ", tops[i]+1);
        }
        printf("\n");
    }

    return 0;
}
