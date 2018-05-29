#include <stdio.h>

int main(void) {
    int testy;
    int godzinaI, minutaI;

    scanf("%d", &testy);

    while(testy--) {
        scanf("%d:%d", &godzinaI, &minutaI);

        if(minutaI == 0) {
            if(godzinaI == 12 || godzinaI == 0) {

            } else godzinaI = 12 - godzinaI;
        } else {
            minutaI = 60 - minutaI;
            godzinaI = 11 - godzinaI;
        }
        if(godzinaI == 0) godzinaI = 12;
        if(godzinaI == -1) godzinaI = 11;

        if(godzinaI >= 10) {
            if(minutaI >= 10) printf("%d:%d\n", godzinaI, minutaI);
            else printf("%d:0%d\n", godzinaI, minutaI);
        } else {
            if(minutaI >= 10)  printf("0%d:%d\n", godzinaI, minutaI);
            else  printf("0%d:0%d\n", godzinaI, minutaI);
        }
    }

    return 0;
}
