#include <stdio.h>

int main()
{
    double x, y, x_plus_y, x_minus_y;

    printf("Enter value of:\nx + y = ");
    scanf("%lf", &x_plus_y);
    printf("Enter value of:\nx - y = ");
    scanf("%lf", &x_minus_y);

    x = (x_plus_y + x_minus_y) / 2;
    y = (x_plus_y - x_minus_y) / 2;

    printf("x = %.2lf\ny = %.2lf", x, y);

    return 0;
}