#include <stdio.h>

int main()
{
    int temp, a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (c > d) {
        temp = c;
        c = d;
        d = temp;
    }
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    printf("%d %d %d %d\n", a, b, c, d);

    return 0;
}