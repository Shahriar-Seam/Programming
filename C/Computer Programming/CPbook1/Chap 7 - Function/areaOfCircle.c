#include <stdio.h>
#include <math.h>

double pi = 3.141592653589793;

double areaOfCircle(double r)
{
    double area = pi * pow(r, 2);

    return area;
}

int main()
{
    double r;
    
    printf("Enter radius of the circle: ");
    scanf("%lf", &r);

    double area = areaOfCircle(r);

    printf("The area of the circle is: %.2lf", area);

    return 0;
}