#include <stdio.h>
#include <math.h>

int main()
{
    double x1, x2, y1, y2, d;

    printf("Enter coordinates of first point: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter coordinates of second point: ");
    scanf("%lf %lf", &x2, &y2);

    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    printf("%lf\n", d);

    return 0;
}