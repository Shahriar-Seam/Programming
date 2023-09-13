#include <stdio.h>
#include <math.h>

int main()
{
    double x, s;

    scanf("%lf", &x);

    s = pow((cos((2 * x) - 1)), 2);

    printf("%.2lf\n", s);

    return 0;
}