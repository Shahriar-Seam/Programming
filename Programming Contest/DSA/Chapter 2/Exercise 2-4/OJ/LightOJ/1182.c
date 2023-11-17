#include <stdio.h>

int main()
{
    int t, n, count, i;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        scanf("%d", &n);

        count = 0;

        while (n) {
            n = n & (n - 1);
            count++;
        }

        printf("Case %d: %s\n", i, (count % 2 == 1) ? "odd" : "even");
    }

    return 0;
}