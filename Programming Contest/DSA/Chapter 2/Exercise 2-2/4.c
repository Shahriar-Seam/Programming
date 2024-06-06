#include <stdio.h>
#include <math.h>

int main()
{
    double r, pi, p;

    scanf("%lf", &r);

    pi = acos(-1);
    p = 2 * pi * r;

    printf("%g\n", p);

    return 0;
}