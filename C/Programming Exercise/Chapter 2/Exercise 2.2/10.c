#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, n = 0;

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    if (a >= 30) {
        n += 1;
    }
    if (b >= 30) {
        n += 1;
    }
    if (c >= 30) {
        n += 1;
    }
    if (d >= 30) {
        n += 1;
    }
    if (e >= 30) {
        n += 1;
    }
    if (f >= 30) {
        n += 1;
    }

    printf("\n%d\n", n);

    return 0;
}