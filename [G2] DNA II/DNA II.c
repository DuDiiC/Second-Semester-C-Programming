#include <stdio.h>
#include <string.h>

int main(void) {

    int cases, i;
    scanf("%d", &cases);

    for(i = 1; i <= cases; ++i) {
        char zasady[31];
        int dlugoscNapisu, j;
        unsigned long long koncowaLiczba = 0, potegiCzworki[30];
        potegiCzworki[0] = 1;
        for(j = 1; j < 30; ++j) {
            potegiCzworki[j] = 4*potegiCzworki[j-1];
        }
        scanf("%s", &zasady);

        dlugoscNapisu = strlen(zasady);

        for(j = dlugoscNapisu-1; j >=0; --j) {
            if(zasady[j] == 'C') koncowaLiczba += potegiCzworki[dlugoscNapisu-1-j];
            else if(zasady[j] == 'G') koncowaLiczba += 2*potegiCzworki[dlugoscNapisu-1-j];
            else if(zasady[j] == 'T') koncowaLiczba += 3*potegiCzworki[dlugoscNapisu-1-j];
        }

        printf("Case %d: (%d:%llu)\n", i, dlugoscNapisu, koncowaLiczba);
    }

    return 0;
}
