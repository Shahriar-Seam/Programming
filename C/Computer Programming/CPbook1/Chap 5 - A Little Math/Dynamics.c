#include <stdio.h>

int main()
{
    double s, v, t;

    printf("Enter velocity and time: ");
    scanf("%lf %lf", &v, &t);

    s = 2 * v * t;

    printf("Distance = %.2lf", s);

    return 0;
}