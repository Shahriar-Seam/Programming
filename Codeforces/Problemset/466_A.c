#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, a, b, p1, p2, p3, p;

    scanf("%d %d %d %d", &n, &m, &a, &b);

    p1 = (n / m) * b + (n - (n / m) * m) * a;
    p2 = n * a;
    p3 = ceil((double) n / m) * b;

    p = (p1 < p2) ? p1 : p2;
    p = (p < p3) ? p : p3;

    printf("%d", p);

    return 0;
}