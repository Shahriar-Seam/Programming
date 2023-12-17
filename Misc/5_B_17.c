#include <stdio.h>

int main()
{
    int fib[45] = {0}, i, n;
    fib[0] = fib[1] = 1;

    scanf("%d", &n);

    printf("%d %d ", fib[0], fib[1]);

    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        printf("%d ", fib[i]);
    }

    return 0;
}