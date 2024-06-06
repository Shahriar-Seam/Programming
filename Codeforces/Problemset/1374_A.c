#include <stdio.h>

int main()
{
    int t;
    int x, y, n, k;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &x, &y, &n);

        k = (n - y) / x;
        k = x * k + y;

        printf("%d\n", k);
    }

    return 0;
}