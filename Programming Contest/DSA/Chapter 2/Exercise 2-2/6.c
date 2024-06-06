#include <stdio.h>
#include <math.h>

int main()
{
    double x1, x2, x3, y1, y2, y3;
    double a, b, c, s, area;

    printf("Enter coordinates of first point: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter coordinates of second point: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter coordinates of third point: ");
    scanf("%lf %lf", &x3, &y3);

    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));

    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("Area = %g\n", area);

    return 0;
}