#include <stdio.h>

int main()
{
    double x, y, c1, c2;  // c1 = x + y, c2 = x - y

    scanf("%lf %lf", &c1, &c2);

    x = (c1 + c2) / 2;
    y = (c1 - c2) / 2;

    printf("x = %g\ny = %g\n", x, y);

    return 0;
}