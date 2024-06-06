#include <stdio.h>

int main()
{
    double p = 10000, n1 = 6, r1 = 3.5 / 100.0, n2 = 9, r2 = 2.0 / 100.0, i1, i2;

    i1 = p * n1 * r1;
    i2 = p * n2 * r2;

    printf("%.2lf\n%.2lf\n", i1, i2);

    if (i1 > i2) {
        printf("Jitsen.\n");
    }
    else if (i1 < i2) {
        printf("Thoksen.\n");
    }
    else {
        printf("Draw.\n");
    }

    return 0;
}