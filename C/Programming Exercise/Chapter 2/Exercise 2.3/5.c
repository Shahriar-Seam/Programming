#include <stdio.h>

int main()
{
    double p = 10000, t1 = 3 * 12 / 6, r1 = 3.5 / 100, t2 = 3 * 12 / 4, r2 = 2 / 100;

    double i1 = p * t1 * r1;
    double i2 = p * t2 * r2;

    if (i1 > i2) {
        printf("Upokrito hoisen\n");
    }
    else {
        printf("khotigrosto hoisen\n");
    }

    return 0;
}