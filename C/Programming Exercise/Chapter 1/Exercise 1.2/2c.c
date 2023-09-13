#include <stdio.h>
#include <math.h>

int main()
{
    double x, s, pi;
    pi = acos(-1);

    scanf("%lf", &x);

    s = sin((x * pi / 180) / 2);

    printf("%.2lf", s);

    return 0;
}