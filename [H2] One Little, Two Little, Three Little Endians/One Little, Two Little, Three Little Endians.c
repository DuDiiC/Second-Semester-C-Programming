#include <stdio.h>

union Union {
    int number;
    char bytes[4];
};

int main(void) {
    union Union NumberOrBytes;
    char temp;

    while(scanf("%d", &NumberOrBytes.number) == 1) {
        printf("%d converts to ", NumberOrBytes.number);

        temp = NumberOrBytes.bytes[0];
        NumberOrBytes.bytes[0] = NumberOrBytes.bytes[3];
        NumberOrBytes.bytes[3] = temp;

        temp = NumberOrBytes.bytes[1];
        NumberOrBytes.bytes[1] = NumberOrBytes.bytes[2];
        NumberOrBytes.bytes[2] = temp;

        printf("%d\n", NumberOrBytes.number);
    }

    return 0;
}
