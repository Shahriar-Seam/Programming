#include <stdio.h>

int main()
{
    int a, b, c, d, temp;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > b) {
        temp = b;
        b = a;
        a = temp;
    }

    if (a > c) {
        temp = c;
        c = a;
        a = temp;
    }

    if (a > d) {
        temp = d;
        d = a;
        a = temp;
    }

    if (b > c) {
        temp = c;
        c = b;
        b = temp;
    }

    if (b > d) {
        temp = d;
        d = b;
        b = temp;
    }

    if (c > d) {
        temp = d;
        d = c;
        c = temp;
    }

    printf("%d %d %d %d", a, b, c, d);

    return 0;
}