#include <stdio.h>

int min(int a, int b, int c)
{
    int m;

    if (a < b && a < c) m = a;
    else if (b < a && b < c) m = b;
    else m = c;

    return m;
}

int main()
{
    int n, k, l, c, d, p, nl, np;

    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

    int x = ((k * l) / nl);
    int y = (c * d);
    int z = (p / np);

    printf("%d", min(x, y, z) / n);

    return 0;
}