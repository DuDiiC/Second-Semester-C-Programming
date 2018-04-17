#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int iloscTestow, boolean = 1, i, j = 0;
    char znak;

    scanf("%d", &iloscTestow);
    scanf("%c", &znak);

    for(i = 0; i < iloscTestow; ++i)
    {
        char *wsk = (char*)calloc(129, sizeof(char*));
        while(scanf("%c", &znak) && znak != '\n')
        {
            if(j == 0)
            {
                if(znak == ')' || znak == ']') boolean = 0;
                else wsk[j] = znak;
                ++j;
            }
            else if(znak == '(' || znak == '[')
            {
                wsk[j] = znak;
                ++j;
                boolean = 1;
            }
            else if((wsk[j-1] == '(' && znak == ')') || (wsk[j-1] == '[' && znak == ']'))
            {
                --j;
                boolean = 1;
            }
            else  boolean = 0;
        }

        if(j != 0) boolean = 0;

        j = 0;

        if(boolean == 1) printf("Yes\n");
        else printf("No\n");

        boolean = 1;
        free(wsk);
    }

    return 0;
}
