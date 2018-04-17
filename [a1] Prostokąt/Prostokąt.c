#include <stdio.h>

int main() {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    int a, b, c;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    //dlugosci bokow
    a = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    b = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
    c = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
    //w zaleznosci ktory z nich jest przekatna ustalam ktory bok x,y
    //jest wierzcholkiem przy kacie prostokatnym i z wektorow szukam
    // czwartego wierzcholka
    if(a+b==c) {
        x4 = x1;
        y4 = y1 + y2 - y3;
    } else if(a+c == b) {
        x4 = x2 + x3 - x1;
        y4 = y2 + y3 - y1;
    } else {
        x4 = x2 + x1 - x3;
        y4 = y2 + y1 - y3;
    }

    printf("%d %d\n", x4, y4);

    return 0;
}
