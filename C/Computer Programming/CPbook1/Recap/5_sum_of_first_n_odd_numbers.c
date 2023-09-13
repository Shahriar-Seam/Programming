#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, sum_f, sum_l = 0;

    scanf("%d", &n);

    sum_f = pow(n, 2);

    for (i = 1; i <= 2 * n; i += 2) {
        sum_l += i;
    }

    printf("Sum using formula: %d\n", sum_f);
    printf("Sum using loop: %d\n", sum_l);

    return 0;
}