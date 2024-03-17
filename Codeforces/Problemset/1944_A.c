#include <stdio.h>

int main()
{
    int t, n, k;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        printf("%d\n", (k >= n - 1 ? 1 : n));
    }

    return 0;
}