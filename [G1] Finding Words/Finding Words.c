#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {

    char line[61], word[61];
    int i, j, transfer = 0; /* if in the end of line is '-' change to 1 */
    int lineLength, wordLength = 0;

    fgets(line, 61, stdin);

    while(strlen(line) != 2 || line[0] != '#') { /* string format: ...\0 */

        lineLength = strlen(line);

        for(i = 0; i < lineLength; ++i) {

            if(isalpha(line[i])) {  /* if 'normal' letter */

                word[wordLength] = line[i];
                ++wordLength;

            } else if(line[i] == '-') { /* if word transfer */

                transfer = 1;
                break;

            } else if(isspace(line[i])) { /* end of word */

                for(j = 0; j < wordLength; ++j) printf("%c", word[j]);

                if(transfer == 1) {
                    puts("");
                    transfer = 0;
                }

                printf("%c", line[i]);
                wordLength = 0;

            } /* else do nothing */
        }

        fgets(line, 61, stdin);
    }

    return 0;
}
