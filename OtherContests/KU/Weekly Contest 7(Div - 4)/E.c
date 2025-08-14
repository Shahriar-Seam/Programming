#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int k, n, w;

    scanf("%d %d %d", &k, &n, &w);

    int total = (w * (w + 1)) / 2 * k;

    if (total <= n) {
        printf("0\n");
    }
    else {
        printf("%d\n", total - n);
    }

    return 0;
}