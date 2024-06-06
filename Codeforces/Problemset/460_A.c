#include <stdio.h>

int main()
{
    int n, m, d;

    scanf("%d %d", &n, &m);

    d = n + (n - 1) / (m - 1);

    printf("%d", d);

    return 0;
}