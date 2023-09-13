#include <stdio.h>

int main()
{
    double x, y, c;

    scanf("%lf %lf", &x, &y);

    c = x / y;

    printf("%0.3lf km/l\n", c);

    return 0;
}