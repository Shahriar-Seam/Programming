#include <stdio.h>

int main()
{
    double a, b;

    scanf("%lf %lf", &a, &b);
    printf("Area = %.2lf sq. unit\n", a * b / 2);

    return 0;
}