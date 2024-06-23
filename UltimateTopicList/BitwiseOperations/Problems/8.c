#include <stdio.h>

int main()
{
    int n, mask, count = 0;

    scanf("%d", &n);

    for (mask = 0; (1 << mask) <= n; mask++) {
        if (n & (1 << mask)) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}