#include <stdio.h>
#include <math.h>

int main()
{
    double x, l;

    scanf("%lf", &x);

    l = (log(pow(x, 3)) / log(2)) + 3 * x - 1;

    printf("%.2lf", l);

    return 0;
}