#include <stdio.h>

double pi = 3.141592653589793;

double area_of_circle(double r)
{
    double area = pi * r * r;

    return area;
}

int main()
{
    double r, area;

    printf("Enter radius of the circle: ");
    scanf("%lf", &r);

    area = area_of_circle(r);

    printf("Area = %g\n", area);

    return 0;
}