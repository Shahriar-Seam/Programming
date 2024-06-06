#include <stdio.h>

int main()
{
    double x, y, a1, b1, c1, a2, b2, c2, d;

    printf("Format the equations as ax + by = c\n");
    printf("Enter coefficients of the first equation: ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("Enter coefficients of the second equation: ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    d = (a1 * b2) - (a2 * b1);

    if ((int) d == 0) {
        printf("Value of x and y cannot be determined.\n");
    }

    else {
        x = ((b2 * c1) - (b1 * c2)) / d;
        y = ((a1 * c2) - (a2 * c1)) / d;
    
        printf("x = %g\ny = %g\n", x, y);
    }
    
    return 0;
}