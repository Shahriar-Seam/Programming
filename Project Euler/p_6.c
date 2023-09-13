#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, sum1 = 0, sum2 = 0, d;

    for (i = 1; i <= 100; i++) {
        sum1 += i * i;
    }

    sum2 = 100 * 101 / 2;
    sum2 = sum2 * sum2;

    d = abs(sum2 - sum1);

    printf("%d\n", d);

    return 0;
}