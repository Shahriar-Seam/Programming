#include <stdio.h>

int main()
{
    int i, n, sum = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum += i * (n - i + 1);
    }

    printf("%d\n", sum);

    return 0;
}