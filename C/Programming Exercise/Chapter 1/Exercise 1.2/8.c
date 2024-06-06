#include <stdio.h>
#include <math.h>

int main()
{
    double r, h;
    double pi = acos(-1);

    printf("Enter radius and height of cylinder respectively: ");
    scanf("%lf %lf", &r, &h);
    printf("Volume = %.2lf cubic unit\nSurface Area = %.2lf sq. unit\n", pi * r * r * h, 2 * pi * r * (r + h));

    return 0;
}