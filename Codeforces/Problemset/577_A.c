#include <stdio.h>

int main()
{
    int n, x, i, count = 0;

    scanf("%d %d", &n, &x);

    for (i = 1; i <= n; i++) {
        if (x % i == 0 && x / i <= n) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}