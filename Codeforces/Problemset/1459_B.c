#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int n, k;

    scanf("%d", &n);

    k = n / 2 + !(n % 2);

    printf("%d\n", (n & 1) ? 2 * (k + 1) * (k + 2) :  k * k);

    return 0;
}